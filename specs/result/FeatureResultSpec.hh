<?hh //partial

use specify\result\FeatureResult;
use \Exception;


describe(FeatureResult::class, function() {
    describe('->passed()', function() {
        it('returns passed result', function() {
            $exampleResult = FeatureResult::passed('foo');

            $result = $exampleResult->isPassed();
            expect($result)->toBeTrue();

            $result = $exampleResult->isFailed();
            expect($result)->toBeFalse();

            $result = $exampleResult->isPending();
            expect($result)->toBeFalse();
        });
    });
    describe('->failed()', function() {
        it('returns failed result', function() {
            $exampleResult = FeatureResult::failed('foo', new Exception('failed!!'));
            $result = $exampleResult->isFailed();
            expect($result)->toBeTrue();

            $result = $exampleResult->isPassed();
            expect($result)->toBeFalse();

            $result = $exampleResult->isPending();
            expect($result)->toBeFalse();
        });
    });
    context('->pending()', function() {
        it('returns pending result', function() {
            $exampleResult = FeatureResult::pending('foo');

            $result = $exampleResult->isFailed();
            expect($result)->toBeFalse();

            $result = $exampleResult->isPassed();
            expect($result)->toBeFalse();

            $result = $exampleResult->isPending();
            expect($result)->toBeTrue();
        });
    });
});
