<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\feature;

use specify\Specification;
use specify\AttributeType;
use specify\FeatureSpecification;
use specify\notifier\FeatureNotifier;
use specify\result\FeatureResult;
use \ReflectionMethod;
use \Exception;


class PendingFeature implements FeatureSpecification<FeatureResult, FeatureNotifier>
{

    public function __construct(
        private Specification $target,
        private ReflectionMethod $method
    )
    {
    }

    public function verify(FeatureNotifier $notifier) : FeatureResult
    {
        $description = 'pending';
        $attributeValues = $this->method->getAttribute((string) AttributeType::PendingFeature);

        if ($attributeValues !== null) {
            $description = (string) $attributeValues[0];
        }

        $notifier->featureStart($description);
        $result = FeatureResult::pending($description);
        $notifier->featureFinish($result);

        return $result;
    }

}