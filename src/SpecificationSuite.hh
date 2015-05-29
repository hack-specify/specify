<?hh //strict

namespace minitest;

use \Exception;
use \ReflectionMethod;


abstract class SpecificationSuite implements Specification<ObjectBehaviorResult>
{

    private string $name;

    public function __construct()
    {
        $this->name = str_replace('Spec', '', get_class($this)); //XXX nameed base?
    }

    <<__Memoize>>
    public function verify() : ObjectBehaviorResult
    {
        $collector = new SpecificationCollector();
        $methods = $collector->collectFrom($this);

        $verifyResults = $this->verifyAll($methods);

        return new ObjectBehaviorResult($this->name, $verifyResults);
    }

    private function verifyAll(BehaviorMethodCollection $methods) : MethodBehaviorResultCollection
    {
        $verifyResults = Vector {};

        foreach ($methods as $method) {
            $result = $method->verify();
            $verifyResults->add($result);
        }

        return $verifyResults;
    }

}
