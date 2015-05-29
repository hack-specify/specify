<?hh //strict

namespace minitest\example;

use minitest\SpecificationSuite;
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
