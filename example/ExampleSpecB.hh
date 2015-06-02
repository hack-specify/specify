<?hh //strict

namespace specify\example;

use \Exception;
use specify\Specification;


final class ExampleSpecB implements Specification
{

    <<Example("example1")>>
    public function example1() : void
    {
        throw new Exception('oops!!');
    }

    <<Example("example2")>>
    public function example2() : void
    {
    }

}
