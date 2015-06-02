<?hh //strict

namespace specify\reporter;

use specify\LifeCycleEvent;
use specify\LifeCycleMessageSubscriber;
use specify\event\ExamplePackageStart;
use specify\event\ExampleGroupStart;
use specify\event\ExampleGroupFinish;
use specify\event\ExamplePackageFinish;


class SpecificationReporter implements LifeCycleMessageSubscriber
{

    private int $indentLevel = 0;


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
        echo $event->getDescription(), "\n";
    }

    public function onExampleGroupStart(ExampleGroupStart $event) : void
    {
        $this->indentLevel++;
        echo $event->getDescription(), "\n";
    }

    public function onExampleGroupFinish(ExampleGroupFinish $event) : void
    {
        $result = $event->getExampleGroupResult();
        $indentSpace = str_pad("", $this->indentLevel, " ");

        $exampleResults = $result->getExampleResults();

        foreach ($exampleResults as $exampleResult) {
            $status = $exampleResult->isFailed() ? 'ok' : 'ng';
            echo $indentSpace, $status, " ", $exampleResult->getDescription(), "\n";
        }

        $this->indentLevel--;
    }

    public function onExamplePackageFinish(ExamplePackageFinish $event) : void
    {
        $result = $event->getExamplePackageResult();
        echo "\n";
        echo $result->getExampleCount(), " example, ", $result->getFailedExampleCount(), " failures\n";
    }

}
