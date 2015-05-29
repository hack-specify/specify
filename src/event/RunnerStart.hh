<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use DateTimeImmutable;


class RunnerStart implements LifeCycleEvent
{
    use NamedEvent;

    public function __construct()
    {
        $this->name = self::RUNNER_START;
        $this->sendAt = new DateTimeImmutable();
    }

}
