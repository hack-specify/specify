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

class ExampleGroupResult implements VerifyResult
{

    public function __construct(
        private string $description,
        private ExampleResultCollection $exampleResults,
        private ProcessingTime $processingTime,
    )
    {
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function getExampleResults() : ExampleResultCollection
    {
        return $this->exampleResults;
    }

    public function getProcessingTime() : ProcessingTime
    {
        return $this->processingTime;
    }

    <<__Memoize>>
    public function getExampleCount() : int
    {
        return $this->exampleResults->count();
    }

    <<__Memoize>>
    public function getPendingExampleCount() : int
    {
        $pendingExamples = $this->exampleResults->filter((ExampleResult $exampleResult) ==> {
            return $exampleResult->isPending();
        });

        return $pendingExamples->count();
    }

    <<__Memoize>>
    public function getFailedExampleCount() : int
    {
        $failedExamples = $this->getFailedExamples();
        return $failedExamples->count();
    }

    <<__Memoize>>
    public function getFailedExamples() : ExampleResultCollection
    {
        $failedExamples = $this->exampleResults->filter((ExampleResult $exampleResult) ==> {
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
