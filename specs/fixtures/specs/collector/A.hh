<?hh //strict

namespace specify\fixtures\collector;

use specify\Specification;

class A implements Specification
{

    <<Example("example1")>>
    public function example1() : void
    {
    }

    <<PendingExample("example2")>>
    public function example2() : void
    {
    }

}
