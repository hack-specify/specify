<?hh //partial

use specify\feature\FeatureVerifierBuilder;
use specify\notifier\NullNotifier;


describe(FeatureVerifierBuilder::class, function() {
    describe('->verify()', function() {
        beforeEach(function() {
            $this->stack = Vector {};

            $feature = new FeatureVerifierBuilder();

            $feature->setup(() ==> {
                $this->stack = Vector {};
            });

            $feature->when(() ==> {
                $this->stack->add(1);
            });

            $feature->then(() ==> {
                invariant($this->stack->count() === 1, 'should be count 1');
            });

            $this->verifier = $feature->build();
        });
        it('verify success', function() {
            $this->verifier->verify(new NullNotifier());
        });
    });
});
