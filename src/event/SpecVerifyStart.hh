<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;

class SpecVerifyStart implements LifeCycleEvent
{

    use NamedEvent;

    public function __construct()
    {
        $this->name = self::SPEC_VERIFY_START;
    }

}
