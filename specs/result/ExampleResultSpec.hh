<?hh //partial

use specify\result\ExampleResult;
use \Exception;


describe(ExampleResult::class, function() {
    describe('->passed()', function() {
        it('returns passed result', function() {
            $exampleResult = ExampleResult::passed('foo');
            $result = $exampleResult->isPassed();
            expect($result)->toBeTrue();
        });
    });
    describe('->failed()', function() {
        it('returns failed result', function() {
            $exampleResult = ExampleResult::failed('foo', new Exception('failed!!'));
            $result = $exampleResult->isFailed();
            expect($result)->toBeTrue();

            $result = $exampleResult->isPassed();
            expect($result)->toBeFalse();
        });
    });
    context('->pending()', function() {
        it('returns pending result', function() {
            $exampleResult = ExampleResult::pending('foo');
            $result = $exampleResult->isFailed();
            expect($result)->toBeFalse();

            $result = $exampleResult->isPassed();
            expect($result)->toBeFalse();

            $result = $exampleResult->isPending();
            expect($result)->toBeTrue();
        });
    });
});
