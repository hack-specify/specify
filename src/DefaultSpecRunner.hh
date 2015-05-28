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
        $notifier->runnerStart();

        $specs = $this->specs->getIterator();

        foreach ($specs as $spec) {
            $spec->verify();
        }

        $notifier->runnerStop();
    }

}
