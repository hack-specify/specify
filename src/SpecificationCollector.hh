<?hh //strict

namespace minitest;

use \ReflectionClass;
use \ReflectionMethod;

class SpecificationCollector implements Collector<Specification, int, ReflectionMethod>
{

    public function collectFrom(Specification $target) : MethodCollection
    {
        $reflection = new ReflectionClass($target);
        $methods = $reflection->getMethods(ReflectionMethod::IS_PUBLIC);

        foreach ($methods as $method) {
            $attribute = $method->getAttribute('Specification');

            if ($attribute === null) {
                continue;
            }
            yield $method;
        }
    }

}
