<?hh //partial

use specify\LifeCycleNotifier;
use specify\runner\ExampleGroupRunner;
use specify\fixtures\A;
use specify\fixtures\example\B;
use specify\result\ExampleGroupResult;
use \ReflectionClass;
use \Prophecy\Prophet;
use \Prophecy\Argument;


describe(ExampleGroupRunner::class, function() {
    describe('->run()', function() {
        beforeEach(function() {
            $this->prophet = new Prophet();

            $notifier = $this->prophet->prophesize(LifeCycleNotifier::class);
            $notifier->specVerifyStart()->shouldBeCalled();
            $notifier->specVerifyFinish(Argument::type(ExampleGroupResult::class))->shouldBeCalled();

            $this->notifier = $notifier->reveal();

            $this->exampleGroup = new ExampleGroupRunner(new ReflectionClass(A::class));
        });
        it('run all examples', function() {
            $this->exampleGroup->run($this->notifier);
            $this->prophet->checkPredictions();
        });
    });
});
