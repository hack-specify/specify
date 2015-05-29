<?hh //strict

namespace minitest;

use minitest\event\RunnerStart;
use minitest\event\SpecVerifyStart;
use minitest\event\SpecVerifyFinish;
use minitest\event\RunnerStop;


class DefaultLifeCycleNotifier implements LifeCycleNotifier
{

    public function __construct(
        private LifeCycleMessageSubscriberCollection $subscribers
    )
    {
    }

    public function runnerStart() : void
    {
        $this->send(new RunnerStart());
    }

    public function specVerifyStart() : void
    {
        $this->send(new SpecVerifyStart());
    }

    public function specVerifyFinish(ObjectBehaviorResult $result) : void
    {
        $this->send(new SpecVerifyFinish($result));
    }

    public function runnerStop() : void
    {
        $this->send(new RunnerStop());
    }

    private function send(LifeCycleEvent $event) : void
    {
        foreach ($this->subscribers as $subscriber) {
            $event->sendTo($subscriber);
        }
    }

}
