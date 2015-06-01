<?hh //strict

namespace specify\event;

use specify\LifeCycleEvent;
use specify\LifeCycleEventType;
use \DateTime;

class ExamplePackageFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct()
    {
        $this->name = LifeCycleEventType::ExamplePackageFinish;
        $this->sendAt = new DateTime();
    }

}
