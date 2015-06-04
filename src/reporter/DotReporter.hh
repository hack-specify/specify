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
use specify\event\ExampleStart;
use specify\event\ExampleFinish;
use specify\event\ExamplePackageFinish;
use specify\io\ConsoleOutput;
use specify\io\Console;


final class DotReporter implements LifeCycleMessageSubscriber
{

    private ReporterCollection $reporters;

    public function __construct(
        private Console $writer = new ConsoleOutput()
    )
    {
        $this->reporters = new CompositionReporter(ImmVector {
            new ProcessingTimeReporter($this->writer),
            new SummaryReporter($this->writer)
        });
    }

    public function handle(LifeCycleEvent $event) : void
    {
        if ($event instanceof ExamplePackageStart) {
            $this->onExamplePackageStart($event);
        } else if ($event instanceof ExampleFinish) {
            $this->onExampleFinish($event);
        } else if ($event instanceof ExamplePackageFinish) {
            $this->onExamplePackageFinish($event);
        }
    }

    private function onExamplePackageStart(ExamplePackageStart $event) : void
    {
        $this->writer->writeln('');
    }

    private function onExampleFinish(ExampleFinish $event) : void
    {
        $value = '.';

        if ($event->isFailed()) {
            $value = '<red>F</red>';
        } else if ($event->isPending()) {
            $value = '<cyan>P</cyan>';
        }

        $this->writer->write($value);
    }

    private function onExamplePackageFinish(ExamplePackageFinish $event) : void
    {
        $this->writer->writeln("\n");
        $event->sendTo($this->reporters);
        $this->writer->write("\n");
    }

}
