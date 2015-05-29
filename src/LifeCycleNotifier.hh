<?hh //strict

namespace specify;

use specify\result\ObjectBehaviorResult;

interface LifeCycleNotifier
{
    public function verifyStart() : void;
    public function specVerifyStart() : void;
    public function specVerifyFinish(ObjectBehaviorResult $result) : void;
    public function verifyFinish() : void;
}
