<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use minitest\LifeCycleEventType;
use DateTimeImmutable;


class VerifyStart extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct()
    {
        $this->name = LifeCycleEventType::VerifyStart;
        $this->sendAt = new DateTimeImmutable();
    }

}
