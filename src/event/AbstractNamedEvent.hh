<?hh //strict

namespace specify\event;

use specify\LifeCycleEvent;
use specify\LifeCycleEventType;
use specify\LifeCycleMessageSubscriber;
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
