<?hh //partial

use specify\example\Example;
use specify\fixtures\A;
use specify\helper\NotifyRecorder;
use \Prophecy\Prophet;
use \Prophecy\Argument;
use \Exception;


describe(Example::class, function() {
    describe('->verify()', function() {
        context('when passed', function() {
            beforeEach(function() {
                $this->notifier = new NotifyRecorder();
            });
            it('returns passed result', function() {
                $target = new A();
                $exampleMethod = new ReflectionMethod($target, 'example1');

                $example = new Example($target, $exampleMethod);
                $result = $example->verify($this->notifier);

                expect($result->getDescription())->toBe("example1");
                expect($result->isPassed())->toBeTrue();
            });
        });
    });
});
