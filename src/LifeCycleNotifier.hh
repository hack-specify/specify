<?hh //strict

namespace minitest;

interface LifeCycleNotifier
{
    public function runnerStart() : void;
    public function specVerifyStart() : void;
    public function specVerifyFinish(ObjectBehaviorResult $result) : void;
    public function runnerStop() : void;
}
