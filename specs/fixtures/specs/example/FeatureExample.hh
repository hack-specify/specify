<?hh //strict

namespace specify\fixtures\example;

use specify\Specification;
use specify\feature\FeatureVerifierBuilder as Feature;
use \Exception;


class FeatureExample implements Specification
{

    <<Feature("example1")>>
    public function example1(Feature $feature) : void
    {
    }

    <<PendingFeature("example2 is pending")>>
    public function example2(Feature $feature) : void
    {
    }

    <<Feature("example3")>>
    public function example3(Feature $feature) : void
    {
        throw new Exception('failed');
    }

}
