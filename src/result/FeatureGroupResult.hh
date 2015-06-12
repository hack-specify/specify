<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\result;

use hhspecify\VerifyResult;
use hhspecify\util\ProcessingTime;

class FeatureGroupResult implements VerifyResult
{

    public function __construct(
        private string $description,
        private FeatureResultCollection $featureResults,
        private ProcessingTime $processingTime,
    )
    {
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function getFeatureResults() : FeatureResultCollection
    {
        return $this->featureResults;
    }

    public function getProcessingTime() : ProcessingTime
    {
        return $this->processingTime;
    }

    <<__Memoize>>
    public function getFeatureCount() : int
    {
        return $this->featureResults->count();
    }

    <<__Memoize>>
    public function getPendingFeatureCount() : int
    {
        $pendingFeatures = $this->featureResults->filter((FeatureResult $featureResult) ==> {
            return $featureResult->isPending();
        });

        return $pendingFeatures->count();
    }

    <<__Memoize>>
    public function getFailedFeatureCount() : int
    {
        $failedFeatures = $this->getFailedFeatures();
        return $failedFeatures->count();
    }

    <<__Memoize>>
    public function getFailedFeatures() : FeatureResultCollection
    {
        $failedFeatures = $this->featureResults->filter((FeatureResult $featureResult) ==> {
            return $featureResult->isFailed();
        });

        return $failedFeatures;
    }

    <<__Memoize>>
    public function isPassed() : bool
    {
        $result = true;
        $featureResults = $this->featureResults->items();

        foreach ($featureResults as $featureResult) {
            if ($featureResult->isPassed() || $featureResult->isPending()) {
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
        $featureResults = $this->featureResults->items();

        foreach ($featureResults as $featureResult) {
            if ($featureResult->isPending()) {
                continue;
            }
            $result = false;
            break;
        }

        return $result;
    }

}
