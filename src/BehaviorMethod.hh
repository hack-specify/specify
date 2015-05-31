<?hh //strict

namespace specify;

use specify\result\ExampleResult;
use \ReflectionMethod;
use \Exception;

class BehaviorMethod implements Specification<ExampleResult>
{

    const string ATTRIBUTE_NAME = 'Specification';

    public function __construct(
        private ObjectBehaviorSpecification $target,
        private ReflectionMethod $method
    )
    {
    }

    public function verify() : ExampleResult
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
