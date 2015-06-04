<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\reporter;

use specify\LifeCycleEvent;
use specify\LifeCycleMessageSubscriber;
use specify\event\ExamplePackageStart;
use specify\event\ExampleGroupStart;
use specify\event\ExampleGroupFinish;
use specify\event\ExamplePackageFinish;
use specify\io\ConsoleOutput;
use specify\io\Console;


final class SpecificationReporter implements LifeCycleMessageSubscriber
{

    private int $indentLevel = 0;
    private CompositionReporter $reporter;

    public function __construct(
        private Console $writer = new ConsoleOutput()
    )
    {
        $this->reporter = new CompositionReporter(ImmVector {
            new ProcessingTimeReporter($this->writer),
            new SummaryReporter($this->writer),
            new FailedExampleReporter($this->writer)
        });
    }

    public function handle(LifeCycleEvent $event) : void
    {
        if ($event instanceof ExamplePackageStart) {
            $this->onExamplePackageStart($event);
        } else if ($event instanceof ExampleGroupStart) {
            $this->onExampleGroupStart($event);
        } else if ($event instanceof ExampleGroupFinish) {
            $this->onExampleGroupFinish($event);
        } else if ($event instanceof ExamplePackageFinish) {
            $this->onExamplePackageFinish($event);
        }
    }

    private function onExamplePackageStart(ExamplePackageStart $event) : void
    {
        $this->writer->writeln("\nPackage: %s\n", $event->getDescription());
        $this->indentLevel++;
    }

    private function onExampleGroupStart(ExampleGroupStart $event) : void
    {
        $indentSpace = str_pad("", $this->indentLevel * 2, " ");

        $this->writer->write($indentSpace . "<white>%s</white>\n", $event->getDescription());
        $this->indentLevel++;
    }

    private function onExampleGroupFinish(ExampleGroupFinish $event) : void
    {
        $result = $event->getExampleGroupResult();
        $exampleResults = $result->getExampleResults();

        $indentSpace = str_pad("", $this->indentLevel * 2, " ");

        foreach ($exampleResults as $exampleResult) {
            $format = "<green>✓</green> <white>%s</white>\n";

            if ($exampleResult->isFailed()) {
                $format = "  <red>%s</red>\n";
            } else if ($exampleResult->isPending()) {
                $format = "  <lightCyan>%s</lightCyan>\n";
            }
            $this->writer->write($indentSpace . $format, $exampleResult->getDescription());
        }

        $this->writer->writeln("");
        $this->indentLevel--;
    }

    private function onExamplePackageFinish(ExamplePackageFinish $event) : void
    {
        $event->sendTo($this->reporter);
    }

}
