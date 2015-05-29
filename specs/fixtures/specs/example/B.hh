<?hh //strict

namespace specify\fixtures\example;

use specify\Specification;
use specify\result\ObjectBehaviorResult;

class B implements Specification<ObjectBehaviorResult>
{

    public function verify() : ObjectBehaviorResult
    {
        return new ObjectBehaviorResult('B', Vector {});
    }

}
