<?hh //strict

namespace specify\event;

use specify\LifeCycleEvent;
use specify\LifeCycleEventType;
use \DateTime;


class ExamplePackageStart extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct()
    {
        $this->name = LifeCycleEventType::ExamplePackageStart;
        $this->sendAt = new DateTime();
    }

}
