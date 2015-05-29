<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use minitest\LifeCycleEventType;
use DateTimeImmutable;

class SpecVerifyStart extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct()
    {
        $this->name = LifeCycleEventType::SpecificationVerifyStart;
        $this->sendAt = new DateTimeImmutable();
    }

}
