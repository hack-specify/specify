<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\reporter;

use hhspecify\LifeCycleEvent;
use hhspecify\LifeCycleMessageSubscriber;
use hhspecify\event\FeaturePackageStart;
use hhspecify\event\FeatureStart;
use hhspecify\event\FeatureFinish;
use hhspecify\event\FeaturePackageFinish;
use hhspecify\io\ConsoleOutput;
use hhspecify\io\Console;


final class DotReporter implements LifeCycleMessageSubscriber
{

    public function __construct(
        private Console $writer = new ConsoleOutput()
    )
    {
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
    }

}
