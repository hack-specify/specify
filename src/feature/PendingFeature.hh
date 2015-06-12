<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\feature;

use hhspecify\Specification;
use hhspecify\AttributeType;
use hhspecify\FeatureSpecification;
use hhspecify\notifier\FeatureNotifier;
use hhspecify\result\FeatureResult;
use \ReflectionMethod;
use \Exception;


class PendingFeature implements FeatureSpecification<FeatureResult, FeatureNotifier>
{

    private FeatureDescription $description;

    public function __construct(
        private Specification $target,
        private ReflectionMethod $method
    )
    {
        $this->description = new FeatureDescription();
        $this->setup();
    }

    private function setup() : void
    {
        $values = $this->method->getAttribute((string) AttributeType::PendingFeature);

        if ($values === null) {
            return;
        }
        $description = (string) $values[0];

        $name = $this->method->getName();
        $detailDescription = str_replace('_', ' ', $name);

        $this->description = new FeatureDescription($description, $detailDescription);
    }

    private function getDescription() : FeatureDescription
    {
        return $this->description;
    }

    public function verify(FeatureNotifier $notifier) : FeatureResult
    {
        $description = $this->getDescription();

        $notifier->featureStart($description);
        $result = FeatureResult::pending($description);
        $notifier->featureFinish($result);

        return $result;
    }

}
