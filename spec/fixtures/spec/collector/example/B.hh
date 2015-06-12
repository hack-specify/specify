<?hh //strict

namespace hhspecify\fixtures\collector\example;

use hhspecify\Specification;

class B implements Specification
{

    <<Feature("example2")>>
    public function example2() : void
    {
    }

    public function example3() : void
    {
    }

}
