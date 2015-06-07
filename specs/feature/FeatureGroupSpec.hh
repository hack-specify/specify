<?hh //partial

use specify\LifeCycleNotifier;
use specify\feature\FeatureGroup;
use specify\result\ExampleGroupResult;
use specify\fixtures\example\Example;
use specify\helper\NotifyRecorder;
use \ReflectionClass;
use \Exception;


describe(FeatureGroup::class, function() {
    describe('->getDescription()', function() {
        beforeEach(function() {
            $this->featureGroup = new FeatureGroup(new ReflectionClass(Example::class));
        });
        it('returns description of feature group', function() {
            expect($this->featureGroup->getDescription())->toBe(Example::class);
        });
    });
    describe('->verify()', function() {
        beforeEach(function() {
            $this->notifier = new NotifyRecorder();
            $this->featureGroup = new FeatureGroup(new ReflectionClass(Example::class));
        });
        it('verify all features', function() {
            $result = $this->featureGroup->verify($this->notifier);
            expect($result->getFeatureCount())->toBe(3);
        });
    });
});
