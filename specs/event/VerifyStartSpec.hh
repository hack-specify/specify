<?hh //partial

use minitest\LifeCycleEventType;
use minitest\event\VerifyStart;

describe('VerifyStart', function() {
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
