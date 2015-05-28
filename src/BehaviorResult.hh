<?hh //strict

namespace minitest;

use \Exception;


class BehaviorResult implements VerifyResult
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

    public function isPass() : bool
    {
        return $this->result === true;
    }

    public function isFailed() : bool
    {
        return $this->isPass() === false;
    }

    public static function pass(string $description) : BehaviorResult
    {
        return new self($description, true);
    }

    public static function failed(string $description, Exception $reason) : BehaviorResult
    {
        return new self($description, false, $reason);
    }

}
