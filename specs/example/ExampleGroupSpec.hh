<?hh //partial

use specify\LifeCycleNotifier;
use specify\example\ExampleGroup;
use specify\result\ExampleGroupResult;
use specify\fixtures\A;
use \ReflectionClass;
use \Exception;
use \Prophecy\Prophet;
use \Prophecy\Argument;


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
            $this->prophet = new Prophet();

            $notifier = $this->prophet->prophesize(LifeCycleNotifier::class);
            $notifier->exampleGroupStart()->shouldBeCalled();
            $notifier->exampleGroupFinish(Argument::type(ExampleGroupResult::class))->shouldBeCalled();

            $this->notifier = $notifier->reveal();
            $this->exampleGroup = new ExampleGroup(new ReflectionClass(A::class));
        });
        it('verify all examples', function() {
            $this->exampleGroup->verify($this->notifier);
            $this->prophet->checkPredictions();
        });
    });
});
