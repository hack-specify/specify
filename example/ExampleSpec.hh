<?hh //strict

namespace minitest\example;

use minitest\AbstractSpecification;
use \Exception;


final class ExampleSpec extends AbstractSpecification
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
