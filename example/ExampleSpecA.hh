<?hh //strict

namespace specify\example;

use \Exception;
use specify\Specification;


final class ExampleSpecA implements Specification
{

    <<Example("example1")>>
    public function example1() : void
    {
    }

    <<Example("example2")>>
    public function example2() : void
    {
        throw new Exception('oops!!');
    }

}
