<?hh //strict

namespace minitest;

use \ReflectionClass;
use \ReflectionMethod;

class SpecificationCollector implements Collector<Specification<void>, int, BehaviorMethod>
{

    public function collectFrom(Specification<void> $target) : BehaviorMethodCollection
    {
        $reflection = new ReflectionClass($target);
        $methods = $reflection->getMethods(ReflectionMethod::IS_PUBLIC);

        foreach ($methods as $method) {
            $attribute = $method->getAttribute(BehaviorMethod::ATTRIBUTE_NAME);

            if ($attribute === null) {
                continue;
            }
            yield new BehaviorMethod($target, $method);
        }
    }

}
