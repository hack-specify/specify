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

        $notifier->verifyStart();

        foreach ($specs as $spec) {
            $notifier->specVerifyStart();
            $behaviorResult = $spec->verify();
            $notifier->specVerifyFinish($behaviorResult);
        }

        $notifier->verifyFinish();
    }

}
