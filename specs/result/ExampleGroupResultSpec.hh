<?hh //partial

use specify\result\ExampleResult;
use specify\result\ExampleGroupResult;
use \Exception;


describe(ExampleGroupResult::class, function() {
    describe('->isPassed()', function() {
        context('when passed', function() {
            it('returns true', function() {
                $groupResult = new ExampleGroupResult('foo', Vector {
                    ExampleResult::passed('foo->bar()')
                });
                $result = $groupResult->isPassed();
                expect($result)->toBeTrue();
            });
        });
    });
    describe('->isFailed()', function() {
        context('when failed', function() {
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
    describe('->isPending()', function() {
        context('when failed', function() {
            it('returns false', function() {
                $groupResult = new ExampleGroupResult('foo', Vector {
                    ExampleResult::failed('foo->bar()'),
                    ExampleResult::pending('foo->foo()')
                });
                $result = $groupResult->isPending();
                expect($result)->toBeFalse();

                $result = $groupResult->isPassed();
                expect($result)->toBeFalse();

                $result = $groupResult->isFailed();
                expect($result)->toBeTrue();
            });
        });
        context('when pending', function() {
            it('returns true', function() {
                $groupResult = new ExampleGroupResult('foo', Vector {
                    ExampleResult::pending('foo->bar()'),
                    ExampleResult::pending('foo->foo()')
                });
                $result = $groupResult->isPending();
                expect($result)->toBeTrue();

                $result = $groupResult->isPassed();
                expect($result)->toBeTrue();

                $result = $groupResult->isFailed();
                expect($result)->toBeFalse();
            });
        });
    });
});
