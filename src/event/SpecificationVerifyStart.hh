<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use minitest\LifeCycleEventType;
use \DateTime;

class SpecificationVerifyStart extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct()
    {
        $this->name = LifeCycleEventType::SpecificationVerifyStart;
        $this->sendAt = new DateTime();
    }

}
