<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\example;

use specify\Specification;
use specify\SpecificationExample;
use specify\LifeCycleNotifier;
use specify\result\ExampleResult;
use \ReflectionMethod;
use \Exception;


class Example implements SpecificationExample<ExampleResult>
{

    const string ATTRIBUTE_NAME = 'Example';

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

        $result = ExampleResult::passed($description);

        try {
            $this->method->invoke($this->target);
        } catch (Exception $exception) {
            $result = ExampleResult::failed($description, $exception);
        }

        return $result;
    }

}
