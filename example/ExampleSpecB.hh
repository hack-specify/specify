<?hh //strict

namespace specify\example;

use \Exception;
use specify\Specification;
use specify\feature\FeatureVerifierBuilder as Feature;


final class ExampleSpecB implements Specification
{

    <<Feature("example1")>>
    public function example1(Feature $feature) : void
    {
        throw new Exception('oops!!');
    }

    <<Feature("example2")>>
    public function example2(Feature $feature) : void
    {
    }

}
