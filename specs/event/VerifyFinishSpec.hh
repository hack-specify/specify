<?hh //partial

use minitest\LifeCycleEventType;
use minitest\event\VerifyFinish;

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
