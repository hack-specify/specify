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

class FeatureGroupResult implements VerifyResult
{

    public function __construct(
        private string $description,
        private FeatureResultCollection $exampleResults,
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
        return $this->exampleResults;
    }

    public function getProcessingTime() : ProcessingTime
    {
        return $this->processingTime;
    }

    <<__Memoize>>
    public function getFeatureCount() : int
    {
        return $this->exampleResults->count();
    }

    <<__Memoize>>
    public function getPendingFeatureCount() : int
    {
        $pendingExamples = $this->exampleResults->filter((FeatureResult $exampleResult) ==> {
            return $exampleResult->isPending();
        });

        return $pendingExamples->count();
    }

    <<__Memoize>>
    public function getFailedFeatureCount() : int
    {
        $failedExamples = $this->getFailedFeatures();
        return $failedExamples->count();
    }

    <<__Memoize>>
    public function getFailedFeatures() : FeatureResultCollection
    {
        $failedExamples = $this->exampleResults->filter((FeatureResult $exampleResult) ==> {
            return $exampleResult->isFailed();
        });

        return $failedExamples;
    }

    <<__Memoize>>
    public function isPassed() : bool
    {
        $result = true;
        $exampleResults = $this->exampleResults->items();

        foreach ($exampleResults as $exampleResult) {
            if ($exampleResult->isPassed() || $exampleResult->isPending()) {
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
        $exampleResults = $this->exampleResults->items();

        foreach ($exampleResults as $exampleResult) {
            if ($exampleResult->isPending()) {
                continue;
            }
            $result = false;
            break;
        }

        return $result;
    }

}
