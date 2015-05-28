<?hh //strict

namespace minitest;

class DefaultLifeCycleNotifier implements LifeCycleNotifier
{

    public function __construct(
        private LifeCycleMessageSubscriberCollection $subscribers
    )
    {
    }

    public function runnerStart() : void
    {
        foreach ($this->subscribers as $subscriber) {
            $subscriber->onRunnerStart();
        }
    }

    public function runnerStop() : void
    {
        foreach ($this->subscribers as $subscriber) {
            $subscriber->onRunnerStop();
        }
    }

}
