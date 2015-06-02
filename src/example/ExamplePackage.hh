<?hh //strict

namespace specify\example;

use specify\SpecificationExample;
use specify\LifeCycleNotifier;
use specify\result\ExamplePackageResult;


class ExamplePackage implements SpecificationExample<ExamplePackageResult>
{

    public function __construct(
        private string $description,
        private ExampleGroupCollection $exampleGroups
    )
    {
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function verify(LifeCycleNotifier $notifier) : ExamplePackageResult
    {
        $groupResults = Vector {};
        $notifier->examplePackageStart($this->getDescription());

        foreach ($this->exampleGroups as $exampleGroup) {
            $result = $exampleGroup->verify($notifier);
            $groupResults->add($result);
        }

        $packageResult = new ExamplePackageResult($this->getDescription(), $groupResults);
        $notifier->examplePackageFinish($packageResult);

        return $packageResult;
    }

}
