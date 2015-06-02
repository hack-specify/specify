<?hh //strict

namespace specify\fixtures\example;

use specify\Specification;

class B implements Specification
{

    <<Example("example2")>>
    public function example2() : void
    {
    }

}
