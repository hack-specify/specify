<?hh //strict

namespace specify;

interface LifeCycleEvent
{
    public function sendTo(LifeCycleMessageSubscriber $subscriber) : void;
}
