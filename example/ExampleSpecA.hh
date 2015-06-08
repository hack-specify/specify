<?hh //strict

namespace specify\example;

use \Exception;
use specify\Specification;
use specify\feature\FeatureVerifierBuilder as Feature;


final class ExampleSpecA implements Specification
{

    <<Feature("example1")>>
    public function example1(Feature $feature) : void
    {
    }

    <<Feature("example2")>>
    public function example2(Feature $feature) : void
    {
        throw new Exception('oops!!');
    }

    <<PendingFeature("example3")>>
    public function example3(Feature $feature) : void
    {
    }

}
