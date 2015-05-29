<?hh //strict

namespace minitest;

use minitest\event\VerifyStart;
use minitest\event\SpecificationVerifyStart;
use minitest\event\SpecificationVerifyFinish;
use minitest\event\VerifyFinish;


class DefaultLifeCycleNotifier implements LifeCycleNotifier
{

    public function __construct(
        private LifeCycleMessageSubscriberCollection $subscribers
    )
    {
    }

    public function verifyStart() : void
    {
        $this->send(new VerifyStart());
    }

    public function specVerifyStart() : void
    {
        $this->send(new SpecificationVerifyStart());
    }

    public function specVerifyFinish(ObjectBehaviorResult $result) : void
    {
        $this->send(new SpecificationVerifyFinish($result));
    }

    public function verifyFinish() : void
    {
        $this->send(new VerifyFinish());
    }

    private function send(LifeCycleEvent $event) : void
    {
        foreach ($this->subscribers as $subscriber) {
            $event->sendTo($subscriber);
        }
    }

}
