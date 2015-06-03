<?hh //partial

use specify\LifeCycleNotifier;
use specify\example\ExampleGroup;
use specify\result\ExampleGroupResult;
use specify\fixtures\A;
use specify\helper\NotifyRecorder;
use \ReflectionClass;
use \Exception;


describe(ExampleGroup::class, function() {
    describe('->getDescription()', function() {
        beforeEach(function() {
            $this->exampleGroup = new ExampleGroup(new ReflectionClass(A::class));
        });
        it('returns description of example group', function() {
            expect($this->exampleGroup->getDescription())->toBe("specify\\fixtures\\A");
        });
    });
    describe('->verify()', function() {
        beforeEach(function() {
            $this->notifier = new NotifyRecorder();
            $this->exampleGroup = new ExampleGroup(new ReflectionClass(A::class));
        });
        it('verify all examples', function() {
            $result = $this->exampleGroup->verify($this->notifier);
            expect($result->getExampleCount())->toBe(2);
        });
    });
});
