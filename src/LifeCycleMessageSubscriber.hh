<?hh //strict

namespace specify;

use specify\event\RunnerStart;
use specify\event\SpecVerifyStart;
use specify\event\SpecVerifyFinish;
use specify\event\RunnerStop;

interface LifeCycleMessageSubscriber
{
    public function handle(LifeCycleEvent $event) : void;
}
