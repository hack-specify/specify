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
        echo "onSpecVerifyStart", "\n";
    }

    public function onSpecVerifyFinish(BehaviorResult $result) : void
    {
        echo $result->getDescription(), "\n";
        $methodResults = $result->getMethodResults();

        foreach ($methodResults as $methodResult) {
            $status = $methodResult->isFailed() ? 'ok' : 'ng';
            echo "    ", $status, " ", $methodResult->getDescription(), "\n";
        }
        echo "onSpecVerifyFinish", "\n";
    }

    public function onRunnerStop() : void
    {
        echo "onRunnerStop", "\n";
    }

}
