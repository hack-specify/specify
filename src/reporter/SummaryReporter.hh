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
use hhspecify\event\FeaturePackageFinish;
use hhspecify\io\ConsoleOutput;
use hhspecify\io\Console;


final class SummaryReporter implements LifeCycleMessageSubscriber
{

    public function __construct(
        private Console $writer = new ConsoleOutput()
    )
    {
    }

    public function receive(LifeCycleEvent $event) : void
    {
        if ($event instanceof FeaturePackageFinish) {
            $this->onPackageFinish($event);
        }
    }

    private function onPackageFinish(FeaturePackageFinish $event) : void
    {
        $template = "%d feature, %d failures, %d pending";

        if ($event->isFailed()) {
            $template = "<red>{$template}</red>";
        } else {
            $template = "<green>{$template}</green>";
        }

        $this->writer->writeln($template,
            $event->getFeatureCount(),
            $event->getFailedFeatureCount(),
            $event->getPendingFeatureCount()
        );
    }

}
