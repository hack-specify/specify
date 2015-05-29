<?hh //partial

use specify\LifeCycleEventType;
use specify\event\VerifyStart;

describe(VerifyStart::class, function() {
    describe('->getName()', function() {
        beforeEach(function() {
            $this->message = new VerifyStart();
        });
        it('returns the event name', function() {
            $name = (string) LifeCycleEventType::VerifyStart;
            expect($this->message->getName())->toBe($name);
        });
    });
});
