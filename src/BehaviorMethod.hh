<?hh //strict

namespace minitest;

use \ReflectionMethod;
use \Exception;

class BehaviorMethod implements Specification<MethodBehaviorResult>
{

    const string ATTRIBUTE_NAME = 'Specification';

    public function __construct(
        private Specification<BehaviorResult> $target,
        private ReflectionMethod $method
    )
    {
    }

    public function verify() : MethodBehaviorResult
    {
        $description = 'pending';
        $attributeValues = $this->method->getAttribute(self::ATTRIBUTE_NAME);

        if ($attributeValues !== null) {
            $description = (string) $attributeValues[0];
        }

        $result = MethodBehaviorResult::passed($description);

        try {
            $this->method->invoke($this->target);
        } catch (Exception $exception) {
            $result = MethodBehaviorResult::failed($description, $exception);
        }

        return $result;
    }

}
