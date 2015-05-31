<?hh //strict

namespace specify\example;

use specify\SpecificationExample;
use specify\LifeCycleNotifier;

class ExamplePackage implements SpecificationExample<void>
{

    public function __construct(
        private ExampleGroupCollection $exampleGroups
    )
    {
    }

    public function verify(LifeCycleNotifier $notifier) : void
    {
        $notifier->examplePackageStart();

        foreach ($this->exampleGroups as $exampleGroup) {
            $exampleGroup->verify($notifier);
        }

        $notifier->examplePackageFinish();
    }

}
