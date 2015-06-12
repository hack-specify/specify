<?hh //partial

use hhspecify\LifeCycleNotifier;
use hhspecify\SpecificationExample;
use hhspecify\feature\FeaturePackage;
use hhspecify\feature\FeatureGroup;
use hhspecify\result\FeatureGroupResult;
use hhspecify\result\FeaturePackageResult;
use hhspecify\notifier\NullNotifier;
use hhspecify\fixtures\example\FeatureExample;


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
