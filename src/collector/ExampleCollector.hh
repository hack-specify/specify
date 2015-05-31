<?hh //strict

namespace specify\collector;

use specify\Collector;
use specify\example\Example;
use \ReflectionClass;
use \ReflectionMethod;


class ExampleCollector implements Collector<object, int, Example>
{

    public function collectFrom(object $target) : ExampleCollection
    {
        $reflection = new ReflectionClass($target);
        $methods = $reflection->getMethods(ReflectionMethod::IS_PUBLIC);

        foreach ($methods as $method) {
            $attribute = $method->getAttribute(Example::ATTRIBUTE_NAME);

            if ($attribute === null) {
                continue;
            }
            yield new Example($target, $method);
        }
    }

}
