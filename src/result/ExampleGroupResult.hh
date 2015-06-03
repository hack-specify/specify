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

class ExampleGroupResult implements VerifyResult
{

    public function __construct(
        private string $description,
        private ExampleResultCollection $exampleResults
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

    <<__Memoize>>
    public function getExampleCount() : int
    {
        return $this->exampleResults->count();
    }

    <<__Memoize>>
    public function getFailedExampleCount() : int
    {
        $failedExamples = $this->exampleResults->filter((ExampleResult $exampleResult) ==> {
            return $exampleResult->isPassed();
        });

        return $failedExamples->count();
    }

    <<__Memoize>>
    public function isPassed() : bool
    {
        $result = true;
        $methodResults = $this->exampleResults->getIterator();

        foreach ($methodResults as $methodResult) {
            if ($methodResult->isPassed()) {
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

}
