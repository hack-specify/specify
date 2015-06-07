<?hh //strict

namespace specify\fixtures\collector;

use specify\Specification;

class A implements Specification
{

    <<Feature("example1")>>
    public function example1() : void
    {
    }

    <<PendingFeature("example2")>>
    public function example2() : void
    {
    }

}
