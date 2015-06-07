<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\result;

use specify\VerifyResult;
use specify\util\ProcessingTime;

class FeaturePackageResult implements VerifyResult
{

    public function __construct(
        private string $description,
        private ExampleGroupResultCollection $exampleGroupResults,
        private ProcessingTime $processingTime
    )
    {
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function getFeatureGroupResults() : ExampleGroupResultCollection
    {
        return $this->exampleGroupResults;
    }

    public function getProcessingTime() : ProcessingTime
    {
        return $this->processingTime;
    }

    <<__Memoize>>
    public function getFeatureCount() : int
    {
        $exampleCount = 0;
        $groupResults = $this->exampleGroupResults->items();

        foreach ($groupResults as $groupResult) {
            $exampleCount += $groupResult->getFeatureCount();
        }

        return $exampleCount;
    }

    <<__Memoize>>
    public function getPendingFeatureCount() : int
    {
        $pendingExampleCount = 0;
        $groupResults = $this->exampleGroupResults->items();

        foreach ($groupResults as $groupResult) {
            $pendingExampleCount += $groupResult->getPendingFeatureCount();
        }

        return $pendingExampleCount;
    }

    <<__Memoize>>
    public function getFailedFeatureCount() : int
    {
        $failedExampleCount = 0;
        $groupResults = $this->exampleGroupResults->items();

        foreach ($groupResults as $groupResult) {
            $failedExampleCount += $groupResult->getFailedFeatureCount();
        }

        return $failedExampleCount;
    }

    <<__Memoize>>
    public function getFailedFeatures() : ExampleResultCollection
    {
        $totalFailedExamples = Vector {};

        foreach ($this->exampleGroupResults as $exampleGroupResult) {
            $failedExamples = $exampleGroupResult->getFailedFeatures();
            $totalFailedExamples->addAll($failedExamples);
        }

        return $totalFailedExamples->toImmVector();
    }

    <<__Memoize>>
    public function isPassed() : bool
    {
        $result = true;
        $exampleGroupResults = $this->exampleGroupResults->items();

        foreach ($exampleGroupResults as $exampleGroupResult) {
            if ($exampleGroupResult->isPassed() || $exampleGroupResult->isPending()) {
                continue;
            }
            $result = false;
            break;
        }

        return $result;
    }

    public function isFailed() : bool
    {
        return $this->isPassed() === false;
    }

    <<__Memoize>>
    public function isPending() : bool
    {
        $result = true;
        $exampleGroupResults = $this->exampleGroupResults->items();

        foreach ($exampleGroupResults as $exampleGroupResult) {
            if ($exampleGroupResult->isPending()) {
                continue;
            }
            $result = false;
            break;
        }

        return $result;
    }

}
