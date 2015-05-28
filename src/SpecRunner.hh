<?hh //strict

namespace minitest;

interface SpecRunner
{
    public function run(LifeCycleNotifier $notifier) : void;
}
