<?hh //partial

use specify\Feature;

describe(Feature::class, function() {
    describe('->verify()', function() {
        beforeEach(function() {
            $this->stack = Vector {};
            $this->feature = new Feature();

            $this->feature->setup(() ==> {
                $this->stack = Vector {};
            });

            $this->feature->when(() ==> {
                $this->stack->add(1);
            });

            $this->feature->expect(() ==> {
                invariant($this->stack->count() === 1, 'should be count 1');
            });
        });
        it('verify success', function() {
            $this->feature->verify();
        });
    });
});
