<?hh //strict

namespace specify\example;

use hhspecify\BehaviorResult;
use hhspecify\LifeCycleEvent;
use hhspecify\LifeCycleMessageSubscriber;
use hhspecify\event\FeaturePackageStart;
use hhspecify\event\FeatureGroupStart;
use hhspecify\event\FeatureGroupFinish;
use hhspecify\event\FeaturePackageFinish;


class ExampleMessageSubscriber implements LifeCycleMessageSubscriber
{

    public function receive(LifeCycleEvent $event) : void
    {
        if ($event instanceof FeaturePackageStart) {
            $this->onExamplePackageStart($event);
        } else if ($event instanceof FeatureGroupStart) {
            $this->onExampleGroupStart($event);
        } else if ($event instanceof FeatureGroupFinish) {
            $this->onExampleGroupFinish($event);
        } else if ($event instanceof FeaturePackageFinish) {
            $this->onExamplePackageFinish($event);
        }
    }

    public function onExamplePackageStart(FeaturePackageStart $event) : void
    {
        echo $event->getName(), "\n";
    }

    public function onExampleGroupStart(FeatureGroupStart $event) : void
    {
        echo $event->getName(), "\n";
    }

    public function onExampleGroupFinish(FeatureGroupFinish $event) : void
    {
        $result = $event->getFeatureGroupResult();

        echo $result->getDescription(), "\n";
        $exampleResults = $result->getFeatureResults();

        foreach ($exampleResults as $exampleResult) {
            $status = $exampleResult->isFailed() ? 'ok' : 'ng';
            echo "    ", $status, " ", $exampleResult->getDescription(), "\n";
        }
    }

    public function onExamplePackageFinish(FeaturePackageFinish $event) : void
    {
        echo $event->getName(), "\n";
    }

}
