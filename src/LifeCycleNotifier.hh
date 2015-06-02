<?hh //strict

namespace specify;

use specify\result\ExampleGroupResult;
use specify\result\ExamplePackageResult;


interface LifeCycleNotifier
{
    public function examplePackageStart(string $description) : void;
    public function exampleGroupStart(string $description) : void;
    public function exampleGroupFinish(ExampleGroupResult $result) : void;
    public function examplePackageFinish(ExamplePackageResult $result) : void;
}
