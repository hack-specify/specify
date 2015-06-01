<?hh //strict

namespace specify\event;

use specify\LifeCycleEvent;
use specify\LifeCycleEventType;
use \DateTime;

class ExampleGroupStart extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct()
    {
        $this->name = LifeCycleEventType::ExampleGroupStart;
        $this->sendAt = new DateTime();
    }

}
