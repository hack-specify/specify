<?hh //strict

namespace specify;

interface ExampleRunner
{
    public function run(LifeCycleNotifier $notifier) : void;
}
