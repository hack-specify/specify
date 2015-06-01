<?hh //partial

use specify\example\Example;
use specify\fixtures\A;
use \Prophecy\Prophet;
use \Prophecy\Argument;
use \Exception;


describe(Example::class, function() {
    describe('->verify()', function() {
        context('when passed', function() {
            beforeEach(function() {
                $this->prophet = new Prophet();

                $notifier = $this->prophet->prophesize(LifeCycleNotifier::class);
                $this->notifier = $notifier->reveal();
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
