<?hh //strict

namespace specify\helper;

use specify\LifeCycleEvent;
use specify\LifeCycleNotifier;
use specify\result\ExampleGroupResult;
use specify\result\ExamplePackageResult;


class NotifyRecorder implements LifeCycleNotifier
{

    private string $packageDescription;
    private Vector<string> $groupDescriptions = Vector {};
    private Vector<ExampleGroupResult> $groupResults = Vector {};
    private ExamplePackageResult $packageResult;

    public function examplePackageStart(string $description) : void
    {
        $this->packageDescription = $description;
    }

    public function exampleGroupStart(string $description) : void
    {
        $this->groupDescriptions->add($description);
    }

    public function exampleGroupFinish(ExampleGroupResult $result) : void
    {
        $this->groupResults->add($result);
    }

    public function examplePackageFinish(ExamplePackageResult $result) : void
    {
        $this->packageResult = $result;
    }

}
