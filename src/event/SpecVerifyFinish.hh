<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use minitest\ObjectBehaviorResult;
use DateTimeImmutable;

class SpecVerifyFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private ObjectBehaviorResult $result
    )
    {
        $this->name = self::SPEC_VERIFY_FINISH;
        $this->sendAt = new DateTimeImmutable();
    }

    public function getBehaviorResult() : ObjectBehaviorResult
    {
        return $this->result;
    }

}
