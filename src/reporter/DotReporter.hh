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
use specify\event\FeaturePackageStart;
use specify\event\FeatureStart;
use specify\event\FeatureFinish;
use specify\event\FeaturePackageFinish;
use specify\io\ConsoleOutput;
use specify\io\Console;


final class DotReporter implements LifeCycleMessageSubscriber
{

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

    public function receive(LifeCycleEvent $event) : void
    {
        if ($event instanceof FeaturePackageStart) {
            $this->onPackageStart($event);
        } else if ($event instanceof FeatureFinish) {
            $this->onFeatureFinish($event);
        } else if ($event instanceof FeaturePackageFinish) {
            $this->onPackageFinish($event);
        }
    }

    private function onPackageStart(FeaturePackageStart $event) : void
    {
        $this->writer->writeln('');
    }

    private function onFeatureFinish(FeatureFinish $event) : void
    {
        $value = '.';

        if ($event->isFailed()) {
            $value = '<red>F</red>';
        } else if ($event->isPending()) {
            $value = '<cyan>P</cyan>';
        }

        $this->writer->write($value);
    }

    private function onPackageFinish(FeaturePackageFinish $event) : void
    {
        $this->writer->writeln("\n");
        $event->sendTo($this->reporter);
    }

}
