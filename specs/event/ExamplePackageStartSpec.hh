<?hh //partial

use specify\LifeCycleEventType;
use specify\event\ExamplePackageStart;

describe(ExamplePackageStart::class, function() {
    describe('->getName()', function() {
        beforeEach(function() {
            $this->message = new ExamplePackageStart();
        });
        it('returns the event name', function() {
            $name = (string) LifeCycleEventType::ExamplePackageStart;
            expect($this->message->getName())->toBe($name);
        });
    });
});
