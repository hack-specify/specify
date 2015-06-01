<?hh //strict

namespace specify;

use specify\result\ExampleGroupResult;
use specify\result\ExamplePackageResult;


interface LifeCycleNotifier
{
    public function examplePackageStart() : void;
    public function exampleGroupStart() : void;
    public function exampleGroupFinish(ExampleGroupResult $result) : void;
    public function examplePackageFinish(ExamplePackageResult $result) : void;
}
