<?hh //strict

namespace minitest;

use \Exception;
use \ReflectionMethod;


abstract class AbstractSpecification implements Specification
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

    private function verifyBehavior(ReflectionMethod $method) : void
    {
        $result = BehaviorResult::pass(''); //FIXME description from user attribute

        try {
            $method->invoke($this);
        } catch (Exception $exception) {
            $result = BehaviorResult::failed(''); //FIXME description from user attribute
        }

        $this->verifyResults->add($result);
    }

}
