<?hh //strict

namespace minitest\example;

use minitest\BehaviorResult;
use minitest\LifeCycleEvent;
use minitest\LifeCycleMessageSubscriber;
use minitest\event\RunnerStart;
use minitest\event\SpecVerifyStart;
use minitest\event\SpecVerifyFinish;
use minitest\event\RunnerStop;


class ExampleMessageSubscriber implements LifeCycleMessageSubscriber
{

    public function handle(LifeCycleEvent $event) : void
    {

        if ($event instanceof RunnerStart) {
            $this->onRunnerStart($event);
        } else if ($event instanceof SpecVerifyStart) {
            $this->onSpecVerifyStart($event);
        } else if ($event instanceof SpecVerifyFinish) {
            $this->onSpecVerifyFinish($event);
        } else if ($event instanceof RunnerStop) {
            $this->onRunnerStop($event);
        }
    }

    public function onRunnerStart(RunnerStart $event) : void
    {
        echo $event->getName(), "\n";
    }

    public function onSpecVerifyStart(SpecVerifyStart $event) : void
    {
        echo $event->getName(), "\n";
    }

    public function onSpecVerifyFinish(SpecVerifyFinish $event) : void
    {
        $result = $event->getBehaviorResult();

        echo $result->getDescription(), "\n";
        $methodResults = $result->getMethodResults();

        foreach ($methodResults as $methodResult) {
            $status = $methodResult->isFailed() ? 'ok' : 'ng';
            echo "    ", $status, " ", $methodResult->getDescription(), "\n";
        }
        echo "onSpecVerifyFinish", "\n";
    }

    public function onRunnerStop(RunnerStop $event) : void
    {
        echo $event->getName(), "\n";
    }

}
