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


final class FailedExampleReporter implements LifeCycleMessageSubscriber
{

    public function __construct(
        private Console $writer = new ConsoleOutput()
    )
    {
    }

    public function handle(LifeCycleEvent $event) : void
    {
        if ($event instanceof FeaturePackageFinish) {
            $this->onPackageFinish($event);
        }
    }

    private function onPackageFinish(FeaturePackageFinish $event) : void
    {
        $this->writer->writeln("");

        $failedResults = $event->getFailedFeatures();

        foreach ($failedResults as $orderNo => $failedResult) {
            $description = $failedResult->getDescription();
            $reasonException = $failedResult->getFailedReasonException();

            $this->writer->writeln("%d) %s\n", $orderNo + 1, $description);

            if ($reasonException === null) {
                return;
            }

            $reasonMessage = $reasonException->getMessage();
            $this->writer->writeln("  %s\n", $reasonMessage);
            $this->writer->writeln("  %s:%d\n",
                $reasonException->getFile(),
                $reasonException->getLine()
            );
        }
    }

}
