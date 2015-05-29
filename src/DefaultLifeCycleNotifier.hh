<?hh //strict

namespace minitest;

use minitest\event\VerifyStart;
use minitest\event\SpecVerifyStart;
use minitest\event\SpecVerifyFinish;
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
        $this->send(new SpecVerifyStart());
    }

    public function specVerifyFinish(ObjectBehaviorResult $result) : void
    {
        $this->send(new SpecVerifyFinish($result));
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
