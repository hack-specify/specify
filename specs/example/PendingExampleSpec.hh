<?hh //partial

use specify\example\PendingExample;
use specify\fixtures\example\Example as FixtureExample;
use \Prophecy\Prophet;
use \Prophecy\Argument;
use \Exception;


describe(PendingExample::class, function() {
    describe('->verify()', function() {
        context('when pending', function() {
            beforeEach(function() {
                $this->prophet = new Prophet();

                $notifier = $this->prophet->prophesize(LifeCycleNotifier::class);
                $this->notifier = $notifier->reveal();
            });
            it('returns pending result', function() {
                $target = new FixtureExample();
                $exampleMethod = new ReflectionMethod($target, 'example2');

                $pendingExample = new PendingExample($target, $exampleMethod);
                $result = $pendingExample->verify($this->notifier);

                expect($result->getDescription())->toBe("example2 is pending");
                expect($result->isPassed())->toBeFalse();
                expect($result->isFailed())->toBeFalse();
                expect($result->isPending())->toBeTrue();
            });
        });
    });
});
