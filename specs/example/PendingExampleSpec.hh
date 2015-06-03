<?hh //partial

use specify\example\PendingExample;
use specify\fixtures\A;
use \Prophecy\Prophet;
use \Prophecy\Argument;
use \Exception;


describe(PendingExample::class, function() {
    describe('->verify()', function() {
        context('when passed', function() {
            beforeEach(function() {
                $this->prophet = new Prophet();

                $notifier = $this->prophet->prophesize(LifeCycleNotifier::class);
                $this->notifier = $notifier->reveal();
            });
            it('returns passed result', function() {
                $target = new A();
                $exampleMethod = new ReflectionMethod($target, 'example2');

                $pendingExample = new PendingExample($target, $exampleMethod);
                $result = $pendingExample->verify($this->notifier);

                expect($result->getDescription())->toBe("example2");
                expect($result->isPassed())->toBeTrue();
            });
        });
    });
});
