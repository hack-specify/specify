<?hh //partial

use specify\LifeCycleNotifier;
use specify\feature\ExampleGroup;
use specify\result\ExampleGroupResult;
use specify\fixtures\example\Example;
use specify\helper\NotifyRecorder;
use \ReflectionClass;
use \Exception;


describe(ExampleGroup::class, function() {
    describe('->getDescription()', function() {
        beforeEach(function() {
            $this->exampleGroup = new ExampleGroup(new ReflectionClass(Example::class));
        });
        it('returns description of example group', function() {
            expect($this->exampleGroup->getDescription())->toBe(Example::class);
        });
    });
    describe('->verify()', function() {
        beforeEach(function() {
            $this->notifier = new NotifyRecorder();
            $this->exampleGroup = new ExampleGroup(new ReflectionClass(Example::class));
        });
        it('verify all examples', function() {
            $result = $this->exampleGroup->verify($this->notifier);
            expect($result->getExampleCount())->toBe(3);
        });
    });
});
