<?hh //partial

use specify\LifeCycleEventType;
use specify\event\VerifyFinish;

describe(VerifyFinish::class, function() {
    describe('->getName()', function() {
        beforeEach(function() {
            $this->message = new VerifyFinish();
        });
        it('returns the event name', function() {
            $name = (string) LifeCycleEventType::VerifyFinish;
            expect($this->message->getName())->toBe($name);
        });
    });
});
