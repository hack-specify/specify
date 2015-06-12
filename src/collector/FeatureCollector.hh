<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\collector;

use hhspecify\Collector;
use hhspecify\Specification;
use hhspecify\feature\Feature;
use hhspecify\feature\PendingFeature;
use hhspecify\feature\FeatureSpecificationFactory;
use hhspecify\result\FeatureResult;
use hhspecify\FeatureSpecification;
use \ReflectionClass;
use \ReflectionMethod;


class FeatureCollector implements Collector<Specification, FeatureCollection>
{

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
