<?hh //strict

namespace minitest;

use \Exception;
use \ReflectionMethod;


abstract class AbstractSpecification implements Specification<void>
{

    private VerifyResultCollection $verifyResults;

    public function __construct()
    {
        $this->verifyResults = Vector {};
    }

    public function verify() : void
    {
        $collector = new SpecificationCollector();
        $methods = $collector->collectFrom($this);

        foreach ($methods as $method) {
            $this->verifyBehavior($method);
        }
    }

    private function verifyBehavior(BehaviorMethod $method) : void
    {
        $result = $method->verify();
        $this->verifyResults->add($result);
    }

}
