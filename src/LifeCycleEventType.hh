<?hh //strict

namespace specify;

enum LifeCycleEventType : string
{
    ExamplePackageStart = 'examplePackageStart';
    ExampleGroupStart = 'exampleGroupStart';
    ExampleGroupFinish = 'exampleGroupFinish';
    ExamplePackageFinish = 'examplePackageFinish';
}
