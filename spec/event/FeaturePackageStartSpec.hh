<?hh //partial

use hhspecify\LifeCycleEventType;
use hhspecify\event\FeaturePackageStart;

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
