<?hh //strict

namespace minitest;

use \ReflectionClass;
use \ReflectionMethod;

class SpecificationCollector implements Collector<Specification<BehaviorResult>, int, BehaviorMethod>
{

    public function collectFrom(Specification<BehaviorResult> $target) : BehaviorMethodCollection
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
