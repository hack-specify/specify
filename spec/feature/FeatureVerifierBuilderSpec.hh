<?hh //partial

use hhspecify\feature\FeatureVerifierBuilder;
use hhspecify\notifier\NullNotifier;
use \Exception;
use \InvalidArgumentException;


describe(FeatureVerifierBuilder::class, function() {
    describe('->build()', function() {
        context('when then()', function() {
            beforeEach(function() {
                $this->executedBlock = 0;

                $feature = new FeatureVerifierBuilder();

                $feature->setup(() ==> {
                    $this->executedBlock++;
                });

                $feature->when(() ==> {
                    $this->executedBlock++;
                });

                $feature->then(() ==> {
                    $this->executedBlock++;
                });

                $feature->cleanup(() ==> {
                    $this->executedBlock++;
                });

                $this->verifier = $feature->build();
            });
            it('build the context for default', function() {
                $this->verifier->verify(new NullNotifier());

                expect($this->executedBlock)->toBe(4);
            });
        });
        context('when thenThrown()', function() {
            beforeEach(function() {
                $this->exception = null;
                $this->executedBlock = 0;

                $feature = new FeatureVerifierBuilder();
                $feature->setup(() ==> {
                    $this->executedBlock++;
                });

                $feature->when(() ==> {
                    $this->executedBlock++;
                    throw new InvalidArgumentException();
                });

                $feature->thenThrown((?Exception $exception) ==> {
                    $this->executedBlock++;
                    $this->exception = $exception;
                });

                $this->verifier = $feature->build();
            });
            it('build the context for exception', function() {
                $this->verifier->verify(new NullNotifier());

                expect($this->executedBlock)->toBe(3);
                expect($this->exception)->toBeAnInstanceOf(InvalidArgumentException::class);
            });
        });
    });
});
