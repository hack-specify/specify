<?hh //partial

use specify\LifeCycleEventType;
use specify\event\ExamplePackageFinish;

describe(ExamplePackageFinish::class, function() {
    describe('->getName()', function() {
        beforeEach(function() {
            $this->message = new ExamplePackageFinish();
        });
        it('returns the event name', function() {
            $name = (string) LifeCycleEventType::ExamplePackageFinish;
            expect($this->message->getName())->toBe($name);
        });
    });
});
