<?hh //strict

namespace specify\example;

use specify\SpecificationSuite;
use \Exception;


final class ExampleSpec extends SpecificationSuite
{

    <<Specification("example1")>>
    public function example1() : void
    {
    }

    <<Specification("example2")>>
    public function example2() : void
    {
        throw new Exception('oops!!');
    }

}
