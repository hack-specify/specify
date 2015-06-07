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
use specify\feature\Feature;
use specify\feature\PendingFeature;
use specify\result\FeatureResult;
use specify\FeatureSpecification;
use \ReflectionClass;
use \ReflectionMethod;


class FeatureCollector implements Collector<Specification, FeatureCollection>
{

    private Map<string, ReflectionClass> $registry;


    public function __construct()
    {
        $this->registry = Map {
            Feature::ATTRIBUTE_NAME => new ReflectionClass(Feature::class),
            PendingFeature::ATTRIBUTE_NAME => new ReflectionClass(PendingFeature::class)
        };
    }

    public function collectFrom(Specification $target) : FeatureCollection
    {
        $examples = Vector {};
        $reflection = new ReflectionClass($target);
        $methods = $reflection->getMethods(ReflectionMethod::IS_PUBLIC);

        foreach ($methods as $method) {
            $example = $this->createExample($target, $method);

            if ($example === null) {
                continue;
            }
            $examples->add($example);
        }
        $examples->shuffle();

        return $examples->toImmVector();
    }

    private function createExample(Specification $target, ReflectionMethod $method) : ?FeatureSpecification<FeatureResult>
    {
        $example = null;
        $attributes = $method->getAttributes();

        if ($attributes === null) {
            return $example;
        }

        foreach ($attributes as $key => $attribute) {
            if ($this->registry->contains($key) === false) {
                continue;
            }
            $args = [$target, $method];

            $factory = $this->registry->at($key);
            $example = $factory->newInstanceArgs($args);
            break;
        }

        return $example;
    }

}
