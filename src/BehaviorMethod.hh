<?hh //strict

namespace minitest;

use \ReflectionMethod;
use \Exception;

class BehaviorMethod implements Specification<BehaviorResult>
{

    const string ATTRIBUTE_NAME = 'Specification';

    public function __construct(
        private Specification<void> $target,
        private ReflectionMethod $method
    )
    {
    }

    public function verify() : BehaviorResult
    {
        $description = 'pending';
        $attributeValues = $this->method->getAttribute(self::ATTRIBUTE_NAME);

        if ($attributeValues !== null) {
            $description = (string) $attributeValues[0];
        }

        $result = BehaviorResult::pass($description);

        try {
            $this->method->invoke($this->target);
        } catch (Exception $exception) {
            $result = BehaviorResult::failed($description, $exception);
        }

        return $result;
    }

}
