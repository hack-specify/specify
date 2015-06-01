<?hh //strict

namespace specify\example;

use specify\SpecificationExample;
use specify\LifeCycleNotifier;
use specify\result\ExamplePackageResult;


class ExamplePackage implements SpecificationExample<ExamplePackageResult>
{

    public function __construct(
        private ExampleGroupCollection $exampleGroups
    )
    {
    }

    public function verify(LifeCycleNotifier $notifier) : ExamplePackageResult
    {
        $groupResults = Vector {};
        $notifier->examplePackageStart();

        foreach ($this->exampleGroups as $exampleGroup) {
            $result = $exampleGroup->verify($notifier);
            $groupResults->add($reslut);
        }

        $packageResult = new ExamplePackageResult('', $groupResults); //description!!
        $notifier->examplePackageFinish($packageResult);

        return $packageResult;
    }

}
