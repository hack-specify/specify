<?hh //strict

namespace specify\example;

use \Exception;


final class ExampleSpec
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
