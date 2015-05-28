<?hh //strict

namespace minitest;

interface LifeCycleMessageSubscriber
{
    public function onRunnerStart() : void;
    public function onRunnerStop() : void;
}
