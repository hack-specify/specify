<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\collector;

use specify\Collector;
use specify\Specification;
use specify\example\Example;
use \ReflectionClass;
use \ReflectionMethod;


class ExampleCollector implements Collector<Specification, int, Example>
{

    public function collectFrom(Specification $target) : ExampleCollection
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
