<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use minitest\LifeCycleEventType;
use minitest\LifeCycleMessageSubscriber;
use DateTimeImmutable;

abstract class AbstractNamedEvent implements LifeCycleEvent
{

    protected LifeCycleEventType $name;
    protected DateTimeImmutable $sendAt;

    public function getName() : string
    {
        return (string) $this->name;
    }

    public function getSendAt() : DateTimeImmutable
    {
        return $this->sendAt;
    }

    public function sendTo(LifeCycleMessageSubscriber $subscriber) : void
    {
        $subscriber->handle($this);
    }

}
