<?hh //strict

namespace specify;

use specify\event\VerifyStart;
use specify\event\SpecificationVerifyStart;
use specify\event\SpecificationVerifyFinish;
use specify\event\VerifyFinish;
use specify\result\ObjectBehaviorResult;


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
