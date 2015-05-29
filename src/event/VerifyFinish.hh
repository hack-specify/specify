<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use minitest\LifeCycleEventType;
use \DateTime;

class VerifyFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct()
    {
        $this->name = LifeCycleEventType::VerifyFinish;
        $this->sendAt = new DateTime();
    }

}
