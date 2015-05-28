<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;

class RunnerStop implements LifeCycleEvent
{

    private string $name;

    public function __construct()
    {
        $this->name = 'runnerStop';
    }

}
