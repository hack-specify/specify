<?hh //strict

namespace minitest\example;

use minitest\AbstractSpecification;
use \Exception;


final class ExampleSpec extends AbstractSpecification
{

    <<Specification("example1")>>
    public function example1() : void
    {
        echo 'example1', "\n";
    }

    <<Specification("example2")>>
    public function example2() : void
    {
        echo 'example2', "\n";
    }

}
