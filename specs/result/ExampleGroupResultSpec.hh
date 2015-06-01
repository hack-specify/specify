<?hh //partial

use specify\result\ExampleResult;
use specify\result\ExampleGroupResult;
use \Exception;


describe(ExampleGroupResult::class, function() {
    describe('->isPassed()', function() {
        it('returns passed result', function() {
            $groupResult = new ExampleGroupResult('foo', Vector {
                ExampleResult::passed('foo->bar()')
            });
            $result = $groupResult->isPassed();
            expect($result)->toBeTrue();
        });
    });
    describe('->isFailed()', function() {
        it('returns failed result', function() {
            $groupResult = new ExampleGroupResult('foo', Vector {
                ExampleResult::failed('foo->bar()', new Exception('failed!!'))
            });
            $result = $groupResult->isFailed();
            expect($result)->toBeTrue();

            $result = $groupResult->isPassed();
            expect($result)->toBeFalse();
        });
    });
});
