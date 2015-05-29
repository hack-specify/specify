<?hh //strict

namespace minitest;

use minitest\event\RunnerStart;
use minitest\event\SpecVerifyStart;
use minitest\event\SpecVerifyFinish;
use minitest\event\RunnerStop;

interface LifeCycleMessageSubscriber
{
    public function handle(LifeCycleEvent $event) : void;
}
