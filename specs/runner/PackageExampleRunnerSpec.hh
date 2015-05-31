<?hh //partial

use specify\LifeCycleNotifier;
use specify\ExampleRunner;
use specify\runner\PackageExampleRunner;
use \Prophecy\Prophet;


describe(PackageExampleRunner::class, function() {
    describe('->run()', function() {
        beforeEach(function() {
            $this->prophet = new Prophet();

            $notifier = $this->prophet->prophesize(LifeCycleNotifier::class);
            $notifier->verifyStart()->shouldBeCalled();
            $notifier->verifyFinish()->shouldBeCalled();

            $this->notifier = $notifier->reveal();

            $group1 = $this->prophet->prophesize(ExampleRunner::class);
            $group1->run($this->notifier)->shouldBeCalled();

            $group2 = $this->prophet->prophesize(ExampleRunner::class);
            $group2->run($this->notifier)->shouldBeCalled();

            $this->package = new PackageExampleRunner(ImmVector {
                $group1->reveal(),
                $group2->reveal()
            });
        });
        it('run all example groups', function() {
            $this->package->run($this->notifier);
            $this->prophet->checkPredictions();
        });
    });
});
