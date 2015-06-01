<?hh //strict

namespace specify;

use specify\event\ExamplePackageStart;
use specify\event\ExampleGroupStart;
use specify\event\ExampleGroupFinish;
use specify\event\ExamplePackageFinish;
use specify\result\ExampleGroupResult;
use specify\result\ExamplePackageResult;


class DefaultLifeCycleNotifier implements LifeCycleNotifier
{

    public function __construct(
        private LifeCycleMessageSubscriberCollection $subscribers
    )
    {
    }

    public function examplePackageStart() : void
    {
        $this->send(new ExamplePackageStart());
    }

    public function exampleGroupStart() : void
    {
        $this->send(new ExampleGroupStart());
    }

    public function exampleGroupFinish(ExampleGroupResult $result) : void
    {
        $this->send(new ExampleGroupFinish($result));
    }

    public function examplePackageFinish(ExamplePackageResult $result) : void
    {
        $this->send(new ExamplePackageFinish($result));
    }

    private function send(LifeCycleEvent $event) : void
    {
        foreach ($this->subscribers as $subscriber) {
            $event->sendTo($subscriber);
        }
    }

}
