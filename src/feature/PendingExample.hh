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
use specify\FeatureSpecification;
use specify\LifeCycleNotifier;
use specify\result\ExampleResult;
use \ReflectionMethod;
use \Exception;


class PendingExample implements FeatureSpecification<ExampleResult>
{

    const string ATTRIBUTE_NAME = 'PendingExample';

    public function __construct(
        private Specification $target,
        private ReflectionMethod $method
    )
    {
    }

    public function verify(LifeCycleNotifier $notifier) : ExampleResult
    {
        $description = 'pending';
        $attributeValues = $this->method->getAttribute(self::ATTRIBUTE_NAME);

        if ($attributeValues !== null) {
            $description = (string) $attributeValues[0];
        }

        $notifier->exampleStart($description);
        $result = ExampleResult::pending($description);
        $notifier->exampleFinish($result);

        return $result;
    }

}
