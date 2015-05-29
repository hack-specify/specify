<?hh //strict

namespace minitest\example;

use minitest\BehaviorResult;
use minitest\LifeCycleEvent;
use minitest\LifeCycleMessageSubscriber;
use minitest\event\VerifyStart;
use minitest\event\SpecVerifyStart;
use minitest\event\SpecVerifyFinish;
use minitest\event\VerifyFinish;


class ExampleMessageSubscriber implements LifeCycleMessageSubscriber
{

    public function handle(LifeCycleEvent $event) : void
    {

        if ($event instanceof VerifyStart) {
            $this->onVerifyStart($event);
        } else if ($event instanceof SpecVerifyStart) {
            $this->onSpecVerifyStart($event);
        } else if ($event instanceof SpecVerifyFinish) {
            $this->onSpecVerifyFinish($event);
        } else if ($event instanceof VerifyFinish) {
            $this->onVerifyFinish($event);
        }
    }

    public function onVerifyStart(VerifyStart $event) : void
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

    public function onVerifyFinish(VerifyFinish $event) : void
    {
        echo $event->getName(), "\n";
    }

}
