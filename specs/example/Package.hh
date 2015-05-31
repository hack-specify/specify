<?hh //partial

use specify\LifeCycleNotifier;
use specify\SpecificationExample;
use specify\example\Package;
use \Prophecy\Prophet;


describe(Package::class, function() {
    describe('->verify()', function() {
        beforeEach(function() {
            $this->prophet = new Prophet();

            $notifier = $this->prophet->prophesize(LifeCycleNotifier::class);
            $notifier->verifyStart()->shouldBeCalled();
            $notifier->verifyFinish()->shouldBeCalled();

            $this->notifier = $notifier->reveal();

            $group1 = $this->prophet->prophesize(SpecificationExample::class);
            $group1->verify($this->notifier)->shouldBeCalled();

            $group2 = $this->prophet->prophesize(SpecificationExample::class);
            $group2->verify($this->notifier)->shouldBeCalled();

            $this->package = new Package(ImmVector {
                $group1->reveal(),
                $group2->reveal()
            });
        });
        it('verify all example groups', function() {
            $this->package->run($this->notifier);
            $this->prophet->checkPredictions();
        });
    });
});
