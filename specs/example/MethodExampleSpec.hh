<?hh //partial

use specify\example\MethodExample;
use specify\fixtures\A;
use \Exception;


describe(MethodExample::class, function() {
    describe('->verify()', function() {
        context('when passed', function() {
            it('returns passed result', function() {
                $target = new A();
                $exampleMethod = new ReflectionMethod($target, 'example1');

                $example = new MethodExample($target, $exampleMethod);
                $result = $example->verify();

                expect($result->getDescription())->toBe("example1");
                expect($result->isPassed())->toBeTrue();
            });
        });
    });
});
