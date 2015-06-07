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
use specify\event\FeaturePackageFinish;
use specify\io\ConsoleOutput;
use specify\io\Console;


final class SummaryReporter implements LifeCycleMessageSubscriber
{

    public function __construct(
        private Console $writer = new ConsoleOutput()
    )
    {
    }

    public function handle(LifeCycleEvent $event) : void
    {
        if ($event instanceof FeaturePackageFinish) {
            $this->onExamplePackageFinish($event);
        }
    }

    private function onExamplePackageFinish(FeaturePackageFinish $event) : void
    {
        $template = "%d example, %d failures, %d pending";

        if ($event->isFailed()) {
            $template = "<red>{$template}</red>";
        } else {
            $template = "<green>{$template}</green>";
        }

        $this->writer->writeln($template,
            $event->getExampleCount(),
            $event->getFailedExampleCount(),
            $event->getPendingExampleCount()
        );
    }

}
