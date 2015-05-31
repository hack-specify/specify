<?hh //strict

namespace specify\result;

use specify\VerifyResult;

class ObjectBehaviorResult implements VerifyResult
{

    public function __construct(
        private string $description,
        private ExampleResultCollection $methodResults
    )
    {
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function getMethodResults() : ExampleResultCollection
    {
        return $this->methodResults;
    }

    <<__Memoize>>
    public function isPassed() : bool
    {
        $result = true;
        $methodResults = $this->methodResults->getIterator();

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
