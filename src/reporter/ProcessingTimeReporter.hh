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
use specify\event\ExamplePackageFinish;


class ProcessingTimeReporter implements LifeCycleMessageSubscriber
{

    private float $startAt = 0.0;

    public function handle(LifeCycleEvent $event) : void
    {
        if ($event instanceof ExamplePackageStart) {
            $this->onExamplePackageStart($event);
        } else if ($event instanceof ExamplePackageFinish) {
            $this->onExamplePackageFinish($event);
        }
    }

    public function onExamplePackageStart(ExamplePackageStart $event) : void
    {
        $this->startAt = $event->getSendAtMicrotime();
    }

    public function onExamplePackageFinish(ExamplePackageFinish $event) : void
    {
        $finishAt = $event->getSendAtMicrotime();
        $processingTime = $finishAt - $this->startAt;

        $this->writeln("Finished in %F seconds\n", $processingTime);
    }

    private function writeln(string $format, ...) : void
    {
        $values = func_get_args();
        echo call_user_func_array('sprintf', $values);
    }

}
