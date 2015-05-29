<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;
use DateTimeImmutable;

class RunnerStop extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct()
    {
        $this->name = self::RUNNER_STOP;
        $this->sendAt = new DateTimeImmutable();
    }

}
