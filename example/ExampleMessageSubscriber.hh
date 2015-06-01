<?hh //strict

namespace specify\example;

use specify\BehaviorResult;
use specify\LifeCycleEvent;
use specify\LifeCycleMessageSubscriber;
use specify\event\ExamplePackageStart;
use specify\event\ExampleGroupStart;
use specify\event\ExampleGroupFinish;
use specify\event\ExamplePackageFinish;


class ExampleMessageSubscriber implements LifeCycleMessageSubscriber
{

    public function handle(LifeCycleEvent $event) : void
    {

        if ($event instanceof ExamplePackageStart) {
            $this->onExamplePackageStart($event);
        } else if ($event instanceof ExampleGroupStart) {
            $this->onExampleGroupStart($event);
        } else if ($event instanceof ExampleGroupFinish) {
            $this->onExampleGroupFinish($event);
        } else if ($event instanceof ExamplePackageFinish) {
            $this->onExamplePackageFinish($event);
        }
    }

    public function onExamplePackageStart(ExamplePackageStart $event) : void
    {
        echo $event->getName(), "\n";
    }

    public function onExampleGroupStart(ExampleGroupStart $event) : void
    {
        echo $event->getName(), "\n";
    }

    public function onExampleGroupFinish(ExampleGroupFinish $event) : void
    {
        $result = $event->getExampleGroupResult();

        echo $result->getDescription(), "\n";
        $exampleResults = $result->getExampleResults();

        foreach ($exampleResults as $exampleResult) {
            $status = $exampleResult->isFailed() ? 'ok' : 'ng';
            echo "    ", $status, " ", $exampleResult->getDescription(), "\n";
        }
    }

    public function onExamplePackageFinish(ExamplePackageFinish $event) : void
    {
        echo $event->getName(), "\n";
    }

}
