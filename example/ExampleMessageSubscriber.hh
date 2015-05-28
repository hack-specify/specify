<?hh //strict

namespace minitest\example;

use minitest\LifeCycleMessageSubscriber;

class ExampleMessageSubscriber implements LifeCycleMessageSubscriber
{

    public function onRunnerStart() : void
    {
        echo "onRunnerStart", "\n";
    }

    public function onRunnerStop() : void
    {
        echo "onRunnerStop", "\n";
    }

}
