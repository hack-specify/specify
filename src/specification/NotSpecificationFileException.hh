<?hh //strict

namespace specify\specification;

use \Exception;

class NotSpecificationFileException extends Exception
{

    public function __construct(
        protected string $message = '',
        protected int $code = 0,
        protected ?Exception $previous = null
    )
    {
        parent::__construct($message, $code, $previous);
    }

}
