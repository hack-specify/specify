<?hh //strict

namespace specify\collector;

use specify\Collector;
use specify\example\MethodExample;
use \ReflectionClass;
use \ReflectionMethod;


class ExampleCollector implements Collector<object, int, MethodExample>
{

    public function collectFrom(object $target) : MethodExampleCollection
    {
        $reflection = new ReflectionClass($target);
        $methods = $reflection->getMethods(ReflectionMethod::IS_PUBLIC);

        foreach ($methods as $method) {
            $attribute = $method->getAttribute(MethodExample::ATTRIBUTE_NAME);

            if ($attribute === null) {
                continue;
            }
            yield new MethodExample($target, $method);
        }
    }

}
