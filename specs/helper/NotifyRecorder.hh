<?hh //strict

namespace specify\helper;

use specify\LifeCycleEvent;
use specify\LifeCycleNotifier;
use specify\result\FeatureResult;
use specify\result\FeatureGroupResult;
use specify\result\FeaturePackageResult;


class NotifyRecorder implements LifeCycleNotifier
{

    private ?string $packageDescription;
    private Vector<string> $groupDescriptions = Vector {};
    private Vector<string> $exampleDescriptions = Vector {};
    private Vector<FeatureResult> $exampleResults = Vector {};
    private Vector<FeatureGroupResult> $groupResults = Vector {};
    private ?FeaturePackageResult $packageResult;

    public function featurePackageStart(string $description) : void
    {
        $this->packageDescription = $description;
    }

    public function featureGroupStart(string $description) : void
    {
        $this->groupDescriptions->add($description);
    }

    public function featureStart(string $description) : void
    {
        $this->exampleDescriptions->add($description);
    }

    public function featureFinish(FeatureResult $result) : void
    {
        $this->exampleResults->add($result);
    }

    public function featureGroupFinish(FeatureGroupResult $result) : void
    {
        $this->groupResults->add($result);
    }

    public function featurePackageFinish(FeaturePackageResult $result) : void
    {
        $this->packageResult = $result;
    }

}
