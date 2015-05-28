<?hh //strict

namespace minitest;



class BehaviorResult implements VerifyResult
{

    public function __construct(
        private string $description
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
        $results = $this->methodResults->getIterator();

        foreach ($results as $result) {
            if ($result->isPassed()) {
                continue;
            }
            $result = false;
            break;
        }

        return $result;
    }

    public function isFailed() : bool
    {
        return $this->isPass() === false;
    }

}
