<?hh //strict

namespace specify\result;

use specify\VerifyResult;
use \Exception;


class ExampleResult implements VerifyResult
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
        return $this->isPassed() === false;
    }

    public static function passed(string $description) : ExampleResult
    {
        return new self($description, true);
    }

    public static function failed(string $description, Exception $reason) : ExampleResult
    {
        return new self($description, false, $reason);
    }

}
