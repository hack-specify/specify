<?hh //strict

namespace specify\fixtures\example;

use specify\Specification;
use \Exception;


class FeatureExample implements Specification
{

    <<Feature("example1")>>
    public function example1() : void
    {
    }

    <<PendingFeature("example2 is pending")>>
    public function example2() : void
    {
    }

    <<Feature("example3")>>
    public function example3() : void
    {
        throw new Exception('failed');
    }

}
