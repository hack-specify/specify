<?hh //partial

use specify\LifeCycleNotifier;
use specify\SpecificationExample;
use specify\example\ExamplePackage;
use specify\result\ExampleGroupResult;
use \Prophecy\Prophet;


describe(ExamplePackage::class, function() {
    describe('->verify()', function() {
        beforeEach(function() {
            $this->prophet = new Prophet();

            $notifier = $this->prophet->prophesize(LifeCycleNotifier::class);
            $notifier->examplePackageStart()->shouldBeCalled();
            $notifier->examplePackageFinish()->shouldBeCalled();

            $this->notifier = $notifier->reveal();

            $group1 = $this->prophet->prophesize(SpecificationExample::class);
            $group1->verify($this->notifier)
                ->shouldBeCalled()
                ->willReturn(new ExampleGroupResult('group1', Vector {}));

            $group2 = $this->prophet->prophesize(SpecificationExample::class);
            $group2->verify($this->notifier)
                ->shouldBeCalled()
                ->willReturn(new ExampleGroupResult('group2', Vector {}));

            $this->package = new ExamplePackage('package', ImmVector {
                $group1->reveal(),
                $group2->reveal()
            });
        });
        it('verify all example groups', function() {
            $this->package->verify($this->notifier);
            $this->prophet->checkPredictions();
        });
    });
});
