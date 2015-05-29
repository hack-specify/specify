<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use minitest\LifeCycleEventType;
use DateTimeImmutable;

class VerifyFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct()
    {
        $this->name = LifeCycleEventType::VerifyFinish;
        $this->sendAt = new DateTimeImmutable();
    }

}
