<?hh //strict

namespace minitest;

use \Exception;


class MethodBehaviorResult implements VerifyResult
{

    public function __construct(
        private string $description,
        private bool $result,
        private ?Exception $exception = null
    )
    {
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function isPassed() : bool
    {
        return $this->result === true;
    }

    public function isFailed() : bool
    {
        return $this->isPass() === false;
    }

    public static function passed(string $description) : MethodBehaviorResult
    {
        return new self($description, true);
    }

    public static function failed(string $description, Exception $reason) : MethodBehaviorResult
    {
        return new self($description, false, $reason);
    }

}
