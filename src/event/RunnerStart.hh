<?hh //strict

namespace minitest\event;

use minitest\LifeCycleEvent;


class RunnerStart implements LifeCycleEvent
{

    private string $name;

    public function __construct()
    {
        $this->name = 'runnerStart';
    }

}
