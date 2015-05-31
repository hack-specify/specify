<?hh //strict

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
