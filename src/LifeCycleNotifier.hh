<?hh //strict

namespace specify;

use specify\result\ExampleGroupResult;

interface LifeCycleNotifier
{
    public function examplePackageStart() : void;
    public function exampleGroupStart() : void;
    public function exampleGroupFinish(ExampleGroupResult $result) : void;
    public function examplePackageFinish() : void;
}
