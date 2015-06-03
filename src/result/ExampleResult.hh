<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\result;

use specify\VerifyResult;
use \Exception;


class ExampleResult implements VerifyResult
{

    public function __construct(
        private string $description,
        private ExampleResultType $result,
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
        return $this->result === ExampleResultType::Passed;
    }

    public function isPending() : bool
    {
        return $this->result === ExampleResultType::Pending;
    }

    public function isFailed() : bool
    {
        return $this->result === ExampleResultType::Failed;
    }

    public static function passed(string $description) : ExampleResult
    {
        return new self($description, ExampleResultType::Passed);
    }

    public static function pending(string $description) : ExampleResult
    {
        return new self($description, ExampleResultType::Pending);
    }

    public static function failed(string $description, Exception $reason) : ExampleResult
    {
        return new self($description, ExampleResultType::Failed, $reason);
    }

}
