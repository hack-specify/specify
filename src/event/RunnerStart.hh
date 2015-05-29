<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;


class RunnerStart implements LifeCycleEvent
{

    use NamedEvent;

    public function __construct()
    {
        $this->name = self::RUNNER_START;
    }

}
