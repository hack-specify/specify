<?hh //strict

namespace specify\event;

use specify\LifeCycleEvent;
use specify\LifeCycleEventType;
use \DateTime;

class SpecificationVerifyStart extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct()
    {
        $this->name = LifeCycleEventType::SpecificationVerifyStart;
        $this->sendAt = new DateTime();
    }

}
