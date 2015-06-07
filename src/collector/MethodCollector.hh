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
use specify\AttributeType;
use \ReflectionClass;
use \ReflectionMethod;


class MethodCollector implements Collector<Specification, ImmVector<ReflectionMethod>>
{

    public function __construct(
        private AttributeType $attributeType
    )
    {
    }

    public function collectFrom(Specification $target) : ImmVector<ReflectionMethod>
    {
        $results = Vector {};

        $reflection = new ReflectionClass($target);
        $methods = $reflection->getMethods(ReflectionMethod::IS_PUBLIC);

        foreach ($methods as $method) {
            $attributes = new ImmMap($method->getAttributes());
            $attributeType = (string) $this->attributeType;
            if ($attributes->contains($attributeType) == false) {
                continue;
            }
            $results->add($method);
        }

        return $results->toImmVector();
    }

}
