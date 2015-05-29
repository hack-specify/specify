<?hh //strict

namespace specify\fixtures;

use specify\Specification;
use specify\result\ObjectBehaviorResult;

class A implements Specification<ObjectBehaviorResult>
{

    public function verify() : ObjectBehaviorResult
    {
        return new ObjectBehaviorResult('A', Vector {});
    }

}
