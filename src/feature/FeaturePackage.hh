<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\feature;

use specify\FeatureSpecification;
use specify\LifeCycleNotifier;
use specify\result\ExamplePackageResult;
use specify\util\StopWatch;


class FeaturePackage implements FeatureSpecification<ExamplePackageResult>
{

    private StopWatch $stopWatch;

    public function __construct(
        private string $description,
        private ExampleGroupCollection $exampleGroups
    )
    {
        $this->stopWatch = new StopWatch();
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function verify(LifeCycleNotifier $notifier) : ExamplePackageResult
    {
        $groupResults = Vector {};
        $notifier->examplePackageStart($this->getDescription());

        $this->stopWatch->start();

        foreach ($this->exampleGroups as $exampleGroup) {
            $result = $exampleGroup->verify($notifier);
            $groupResults->add($result);
        }

        $this->stopWatch->stop();
        $totalTime = $this->stopWatch->getResult();

        $packageResult = new ExamplePackageResult(
            $this->getDescription(),
            $groupResults->toImmVector(),
            $totalTime
        );

        $notifier->examplePackageFinish($packageResult);

        return $packageResult;
    }

}
