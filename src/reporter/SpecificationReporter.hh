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


class SpecificationReporter implements LifeCycleMessageSubscriber
{

    private int $indentLevel = 0;
    private ConsoleOutput $writer;
    private ProcessingTimeReporter $reporter;

    public function __construct()
    {
        $this->writer = new ConsoleOutput();
        $this->reporter = new ProcessingTimeReporter();
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

    public function onExamplePackageStart(ExamplePackageStart $event) : void
    {
        $this->writer->writeln("\n%s\n", $event->getDescription());
        $this->indentLevel++;
        $this->reporter->handle($event);
    }

    public function onExampleGroupStart(ExampleGroupStart $event) : void
    {
        $indentSpace = str_pad("", $this->indentLevel * 2, " ");

        $this->writer->write($indentSpace . "<green>%s</green>\n", $event->getDescription());
        $this->indentLevel++;
    }

    public function onExampleGroupFinish(ExampleGroupFinish $event) : void
    {
        $result = $event->getExampleGroupResult();
        $exampleResults = $result->getExampleResults();

        $indentSpace = str_pad("", $this->indentLevel * 2, " ");

        foreach ($exampleResults as $exampleResult) {
            $format = "<green>%s</green>\n";

            if ($exampleResult->isFailed()) {
                $format = "<red>%s</red>\n";
            } else if ($exampleResult->isPending()) {
                $format = "<yellow>%s</yellow>\n";
            }
            $this->writer->write($indentSpace . $format, $exampleResult->getDescription());
        }

        $this->writer->writeln("");
        $this->indentLevel--;
    }

    public function onExamplePackageFinish(ExamplePackageFinish $event) : void
    {
        $this->reporter->handle($event);

        $this->writer->writeln("%d example, %d failures, %d pending",
            $event->getExampleCount(),
            $event->getFailedExampleCount(),
            $event->getPendingExampleCount()
        );
    }

}
