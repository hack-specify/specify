<?hh //strict

namespace specify;

interface SpecRunner
{
    public function run(LifeCycleNotifier $notifier) : void;
}
