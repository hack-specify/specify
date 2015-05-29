<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;

class SpecVerifyFinish implements LifeCycleEvent
{

    use NamedEvent;

    public function __construct()
    {
        $this->name = self::SPEC_VERIFY_FINISH;
    }

}
