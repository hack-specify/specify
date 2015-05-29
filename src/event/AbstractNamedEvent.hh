<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use minitest\LifeCycleMessageSubscriber;
use DateTimeImmutable;

abstract class AbstractNamedEvent implements LifeCycleEvent
{

    protected string $name;
    protected DateTimeImmutable $sendAt;

    public function getName() : string
    {
        return $this->name;
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
