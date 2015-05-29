<?hh //strict

namespace specify\example;

use specify\BehaviorResult;
use specify\LifeCycleEvent;
use specify\LifeCycleMessageSubscriber;
use specify\event\VerifyStart;
use specify\event\SpecificationVerifyStart;
use specify\event\SpecificationVerifyFinish;
use specify\event\VerifyFinish;


class ExampleMessageSubscriber implements LifeCycleMessageSubscriber
{

    public function handle(LifeCycleEvent $event) : void
    {

        if ($event instanceof VerifyStart) {
            $this->onVerifyStart($event);
        } else if ($event instanceof SpecificationVerifyStart) {
            $this->onSpecificationVerifyStart($event);
        } else if ($event instanceof SpecificationVerifyFinish) {
            $this->onSpecificationVerifyFinish($event);
        } else if ($event instanceof VerifyFinish) {
            $this->onVerifyFinish($event);
        }
    }

    public function onVerifyStart(VerifyStart $event) : void
    {
        echo $event->getName(), "\n";
    }

    public function onSpecificationVerifyStart(SpecificationVerifyStart $event) : void
    {
        echo $event->getName(), "\n";
    }

    public function onSpecificationVerifyFinish(SpecificationVerifyFinish $event) : void
    {
        $result = $event->getBehaviorResult();

        echo $result->getDescription(), "\n";
        $methodResults = $result->getMethodResults();

        foreach ($methodResults as $methodResult) {
            $status = $methodResult->isFailed() ? 'ok' : 'ng';
            echo "    ", $status, " ", $methodResult->getDescription(), "\n";
        }
    }

    public function onVerifyFinish(VerifyFinish $event) : void
    {
        echo $event->getName(), "\n";
    }

}
