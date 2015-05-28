<?hh //strict

namespace minitest;

interface LifeCycleMessageSubscriber
{
    public function onRunnerStart() : void;
    public function onSpecVerifyStart() : void;
    public function onSpecVerifyFinish(BehaviorResult $result) : void;
    public function onRunnerStop() : void;
}
