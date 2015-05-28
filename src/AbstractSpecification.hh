<?hh //strict

namespace minitest;

use \ReflectionClass;
use \ReflectionMethod;

abstract class AbstractSpecification implements Specification
{

    public function verify() : void
    {
        $reflection = new ReflectionClass($this);
        $methods = $reflection->getMethods(ReflectionMethod::IS_PUBLIC);

        foreach ($methods as $method) {
            $attribute = $method->getAttribute('Specification');

            if ($attribute === null) {
                continue;
            }
            $method->invoke($this);
        }
    }

}
