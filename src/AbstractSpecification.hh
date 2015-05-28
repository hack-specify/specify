<?hh //strict

namespace minitest;

use \ReflectionClass;
use \ReflectionMethod;

abstract class AbstractSpecification implements Specification
{

    public function verify() : void
    {
        $collector = new SpecificationCollector();
        $methods = $collector->collectFrom($this);

        foreach ($methods as $method) {
            $method->invoke($this);
        }
    }

}
