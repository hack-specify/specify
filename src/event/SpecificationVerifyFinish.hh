<?hh //strict

namespace specify\event;

use specify\LifeCycleEvent;
use specify\LifeCycleEventType;
use specify\result\ObjectBehaviorResult;
use DateTime;

class SpecificationVerifyFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private ObjectBehaviorResult $result
    )
    {
        $this->name = LifeCycleEventType::SpecificationVerifyFinish;
        $this->sendAt = new DateTime();
    }

    public function getBehaviorResult() : ObjectBehaviorResult
    {
        return $this->result;
    }

}
