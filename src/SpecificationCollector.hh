<?hh //strict

namespace specify;

use \ReflectionClass;
use \ReflectionMethod;

class SpecificationCollector implements Collector<ObjectBehaviorSpecification, int, BehaviorMethod>
{

    public function collectFrom(ObjectBehaviorSpecification $target) : BehaviorMethodCollection
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
