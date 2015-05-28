<?hh //strict

namespace minitest;



class BehaviorResult implements VerifyResult
{

    public function __construct(
        private string $description,
        private MethodBehaviorResultCollection $methodResults
    )
    {
    }

    public function getDescription() : string
    {
        return $this->description;
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
