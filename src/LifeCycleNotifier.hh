<?hh //strict

namespace minitest;

interface LifeCycleNotifier
{
    public function runnerStart() : void;
    public function runnerStop() : void;
}
