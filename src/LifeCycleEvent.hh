<?hh //strict

namespace minitest;

interface LifeCycleEvent
{
//    const string RUNNER_START = 'verifyStart';
//    const string SPEC_VERIFY_START = 'specVerifyStart';
//    const string SPEC_VERIFY_FINISH = 'specVerifyFinish';
//    const string RUNNER_STOP = 'verifyFinish';

    public function sendTo(LifeCycleMessageSubscriber $subscriber) : void;
}
