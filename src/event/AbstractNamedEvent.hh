<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use minitest\LifeCycleEventType;
use minitest\LifeCycleMessageSubscriber;
use \DateTime;


abstract class AbstractNamedEvent implements LifeCycleEvent
{

    protected LifeCycleEventType $name;
    protected DateTime $sendAt;

    public function getName() : string
    {
        return (string) $this->name;
    }

    public function getSendAt() : DateTime
    {
        return $this->sendAt;
    }

    public function sendTo(LifeCycleMessageSubscriber $subscriber) : void
    {
        $subscriber->handle($this);
    }

}
