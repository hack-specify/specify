<?hh //strict

namespace specify\event;

use specify\LifeCycleEvent;
use specify\LifeCycleEventType;
use \DateTime;

class ExampleGroupStart extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private string $description
    )
    {
        $this->name = LifeCycleEventType::ExampleGroupStart;
        $this->sendAt = new DateTime();
    }

    public function getDescription() : string
    {
        return $this->description;
    }

}
