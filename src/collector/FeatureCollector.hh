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
use specify\feature\FeatureSpecificationFactory;
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
        $features = $this->collectFeatureFrom($target);
        $pendingFeatures = $this->collectPendingFeatureFrom($target);

        $results = Vector {};
        $results->addAll($features);
        $results->addAll($pendingFeatures);
        $results->shuffle();

        return $results->toImmVector();
    }


    private function collectFeatureFrom(Specification $target) : FeatureCollection
    {
        $factory = new FeatureSpecificationFactory($target);

        $collector = MethodCollector::createForFeature();
        $methods = $collector->collectFrom($target);

        $features = $methods->map((ReflectionMethod $method) ==> {
            return $factory->createFeatureFrom($method);
        });

        return $features->toImmVector();
    }


    private function collectPendingFeatureFrom(Specification $target) : FeatureCollection
    {
        $factory = new FeatureSpecificationFactory($target);

        $collector = MethodCollector::createForPendingFeature();
        $methods = $collector->collectFrom($target);

        $features = $methods->map((ReflectionMethod $method) ==> {
            return $factory->createPendingFeatureFrom($method);
        });

        return $features->toImmVector();
    }

}
