<?hh //strict

namespace specify\event;

use specify\LifeCycleEvent;
use specify\LifeCycleEventType;
use specify\result\ExampleGroupResult;
use DateTime;

class ExampleGroupFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private ExampleGroupResult $result
    )
    {
        $this->name = LifeCycleEventType::ExampleGroupFinish;
        $this->sendAt = new DateTime();
    }

    public function getExampleGroupResult() : ExampleGroupResult
    {
        return $this->result;
    }

}
