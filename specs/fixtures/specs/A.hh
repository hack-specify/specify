<?hh //strict

namespace specify\fixtures;

use specify\Specification;

class A implements Specification
{

    <<Example("example1")>>
    public function example1() : void
    {
    }

}
