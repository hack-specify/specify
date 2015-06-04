<?hh //strict

namespace specify\fixtures\example;

use specify\Specification;
use \Exception;


class Example implements Specification
{

    <<Example("example1")>>
    public function example1() : void
    {
    }

    <<PendingExample("example2 is pending")>>
    public function example2() : void
    {
    }

    <<Example("example3")>>
    public function example3() : void
    {
        throw new Exception('failed');
    }

}
