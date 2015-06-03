<?hh //partial

use specify\LifeCycleNotifier;
use specify\SpecificationExample;
use specify\example\ExamplePackage;
use specify\example\ExampleGroup;
use specify\result\ExampleGroupResult;
use specify\result\ExamplePackageResult;
use specify\helper\NotifyRecorder;
use specify\fixtures\A;
use specify\fixtures\example\B;


describe(ExamplePackage::class, function() {
    describe('->verify()', function() {
        beforeEach(function() {
            $this->notifier = new NotifyRecorder();
            $this->package = new ExamplePackage('package', ImmVector {
                new ExampleGroup(new ReflectionClass(A::class)),
                new ExampleGroup(new ReflectionClass(B::class))
            });
        });
        it('verify all example groups', function() {
            $result = $this->package->verify($this->notifier);
            expect($result->getExampleCount())->toBe(3);
        });
    });
});
