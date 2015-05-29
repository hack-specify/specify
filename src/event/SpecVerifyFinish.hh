<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use minitest\BehaviorResult;
use DateTimeImmutable;

class SpecVerifyFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private BehaviorResult $result
    )
    {
        $this->name = self::SPEC_VERIFY_FINISH;
        $this->sendAt = new DateTimeImmutable();
    }

    public function getBehaviorResult() : BehaviorResult
    {
        return $this->result;
    }

}
