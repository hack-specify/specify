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
        $event = new RunnerStart();

        foreach ($this->subscribers as $subscriber) {
            $subscriber->onRunnerStart($event);
        }
    }

    public function specVerifyStart() : void
    {
        $event = new SpecVerifyStart();

        foreach ($this->subscribers as $subscriber) {
            $subscriber->onSpecVerifyStart($event);
        }
    }

    public function specVerifyFinish(BehaviorResult $result) : void
    {
        $event = new SpecVerifyFinish($result);

        foreach ($this->subscribers as $subscriber) {
            $subscriber->onSpecVerifyFinish($event);
        }
    }

    public function runnerStop() : void
    {
        $event = new RunnerStop();

        foreach ($this->subscribers as $subscriber) {
            $subscriber->onRunnerStop($event);
        }
    }

}
