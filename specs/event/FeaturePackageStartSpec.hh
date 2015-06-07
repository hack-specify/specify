<?hh //partial

use specify\LifeCycleEventType;
use specify\event\FeaturePackageStart;

describe(FeaturePackageStart::class, function() {
    describe('->getName()', function() {
        beforeEach(function() {
            $this->message = new FeaturePackageStart('description');
        });
        it('returns the event name', function() {
            $name = (string) LifeCycleEventType::ExamplePackageStart;
            expect($this->message->getName())->toBe($name);
        });
    });
});
