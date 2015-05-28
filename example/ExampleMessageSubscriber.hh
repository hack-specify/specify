<?hh //strict

namespace minitest\example;

use minitest\BehaviorResult;
use minitest\LifeCycleMessageSubscriber;


class ExampleMessageSubscriber implements LifeCycleMessageSubscriber
{

    public function onRunnerStart() : void
    {
        echo "onRunnerStart", "\n";
    }

    public function onSpecVerifyStart() : void
    {
    }

    public function onSpecVerifyFinish(BehaviorResult $result) : void
    {
    }

    public function onRunnerStop() : void
    {
        echo "onRunnerStop", "\n";
    }

}
