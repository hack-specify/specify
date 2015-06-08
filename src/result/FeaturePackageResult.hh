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
        private FeatureGroupResultCollection $featureGroupResults = ImmVector {},
        private ProcessingTime $processingTime = new ProcessingTime()
    )
    {
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function getFeatureGroupResults() : FeatureGroupResultCollection
    {
        return $this->featureGroupResults;
    }

    public function getProcessingTime() : ProcessingTime
    {
        return $this->processingTime;
    }

    <<__Memoize>>
    public function getFeatureCount() : int
    {
        $exampleCount = 0;
        $groupResults = $this->featureGroupResults->items();

        foreach ($groupResults as $groupResult) {
            $exampleCount += $groupResult->getFeatureCount();
        }

        return $exampleCount;
    }

    <<__Memoize>>
    public function getPendingFeatureCount() : int
    {
        $pendingCount = 0;
        $groupResults = $this->featureGroupResults->items();

        foreach ($groupResults as $groupResult) {
            $pendingCount += $groupResult->getPendingFeatureCount();
        }

        return $pendingCount;
    }

    <<__Memoize>>
    public function getFailedFeatureCount() : int
    {
        $failedCount = 0;
        $groupResults = $this->featureGroupResults->items();

        foreach ($groupResults as $groupResult) {
            $failedCount += $groupResult->getFailedFeatureCount();
        }

        return $failedCount;
    }

    <<__Memoize>>
    public function getFailedFeatures() : FeatureResultCollection
    {
        $totalFailedFeatures = Vector {};

        foreach ($this->featureGroupResults as $featureGroupResult) {
            $failedFeatures = $featureGroupResult->getFailedFeatures();
            $totalFailedFeatures->addAll($failedFeatures);
        }

        return $totalFailedFeatures->toImmVector();
    }

    <<__Memoize>>
    public function isPassed() : bool
    {
        $result = true;
        $featureGroupResults = $this->featureGroupResults->items();

        foreach ($featureGroupResults as $featureGroupResult) {
            if ($featureGroupResult->isPassed() || $featureGroupResult->isPending()) {
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
        $featureGroupResults = $this->featureGroupResults->items();

        foreach ($featureGroupResults as $featureGroupResult) {
            if ($featureGroupResult->isPending()) {
                continue;
            }
            $result = false;
            break;
        }

        return $result;
    }

    public static function createEmptyResult() : FeaturePackageResult
    {
        return new FeaturePackageResult('empty package');
    }

}
