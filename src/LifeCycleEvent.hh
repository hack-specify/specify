<?hh //strict

namespace minitest;

interface LifeCycleEvent
{
    const string RUNNER_START = 'runnerStart';
    const string SPEC_VERIFY_START = 'specVerifyStart';
    const string SPEC_VERIFY_FINISH = 'specVerifyFinish';
    const string RUNNER_STOP = 'runnerStop';

    public function sendTo(LifeCycleMessageSubscriber $subscriber) : void;
}
