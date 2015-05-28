<?hh //strict

namespace minitest;

class DefaultSpecRunner implements SpecRunner
{

    public function __construct(
        private SpecificationCollection $specs
    )
    {
    }

    public function run(LifeCycleNotifier $notifier) : void
    {
        $specs = $this->specs->getIterator();

        $notifier->runnerStart();

        foreach ($specs as $spec) {
            $behaviorResult = $spec->verify();
        }

        $notifier->runnerStop();
    }

}
