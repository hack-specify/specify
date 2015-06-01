<?hh //strict

namespace specify\event;

use specify\LifeCycleEvent;
use specify\LifeCycleEventType;
use specify\result\ExamplePackageResult;
use \DateTime;


class ExamplePackageFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private ExamplePackageResult $result
    )
    {
        $this->name = LifeCycleEventType::ExamplePackageFinish;
        $this->sendAt = new DateTime();
    }

    public function getExamplePackageResult() : ExamplePackageResult
    {
        return $this->result;
    }

}
