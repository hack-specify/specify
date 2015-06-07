<?hh //partial

use specify\LifeCycleNotifier;
use specify\SpecificationExample;
use specify\feature\ExamplePackage;
use specify\feature\ExampleGroup;
use specify\result\ExampleGroupResult;
use specify\result\ExamplePackageResult;
use specify\helper\NotifyRecorder;
use specify\fixtures\example\Example;


describe(ExamplePackage::class, function() {
    describe('->verify()', function() {
        beforeEach(function() {
            $this->notifier = new NotifyRecorder();
            $this->package = new ExamplePackage('package', ImmVector {
                new ExampleGroup(new ReflectionClass(Example::class)),
                new ExampleGroup(new ReflectionClass(Example::class))
            });
        });
        it('verify all example groups', function() {
            $result = $this->package->verify($this->notifier);
            expect($result->getExampleCount())->toBe(6);
        });
    });
});
