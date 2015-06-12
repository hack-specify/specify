<?hh //partial

use specify\LifeCycleNotifier;
use specify\SpecificationExample;
use specify\feature\FeaturePackage;
use specify\feature\FeatureGroup;
use specify\result\FeatureGroupResult;
use specify\result\FeaturePackageResult;
use specify\notifier\NullNotifier;
use specify\fixtures\example\FeatureExample;


describe(FeaturePackage::class, function() {
    describe('->verify()', function() {
        beforeEach(function() {
            $this->notifier = new NullNotifier();
            $this->package = new FeaturePackage('package', ImmVector {
                new FeatureGroup(new FeatureExample()),
                new FeatureGroup(new FeatureExample())
            });
        });
        it('verify all feature groups', function() {
            $result = $this->package->verify($this->notifier);
            expect($result->getFeatureCount())->toBe(6);
        });
    });
});
