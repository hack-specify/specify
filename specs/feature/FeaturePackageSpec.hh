<?hh //partial

use specify\LifeCycleNotifier;
use specify\SpecificationExample;
use specify\feature\FeaturePackage;
use specify\feature\FeatureGroup;
use specify\result\FeatureGroupResult;
use specify\result\FeaturePackageResult;
use specify\helper\NotifyRecorder;
use specify\fixtures\example\Example;


describe(FeaturePackage::class, function() {
    describe('->verify()', function() {
        beforeEach(function() {
            $this->notifier = new NotifyRecorder();
            $this->package = new FeaturePackage('package', ImmVector {
                new FeatureGroup(new ReflectionClass(Example::class)),
                new FeatureGroup(new ReflectionClass(Example::class))
            });
        });
        it('verify all example groups', function() {
            $result = $this->package->verify($this->notifier);
            expect($result->getExampleCount())->toBe(6);
        });
    });
});
