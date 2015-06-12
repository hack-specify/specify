<?hh //partial

use hhspecify\result\FeatureResult;
use hhspecify\result\FeatureGroupResult;
use \Exception;


describe(FeatureGroupResult::class, function() {
    describe('->isPassed()', function() {
        context('when passed', function() {
            it('returns true', function() {
                $groupResult = new FeatureGroupResult('foo', Vector {
                    FeatureResult::passed('foo->bar()')
                });
                $result = $groupResult->isPassed();
                expect($result)->toBeTrue();
            });
        });
    });
    describe('->isFailed()', function() {
        context('when failed', function() {
            it('returns failed result', function() {
                $groupResult = new FeatureGroupResult('foo', Vector {
                    FeatureResult::failed('foo->bar()', new Exception('failed!!'))
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
                $groupResult = new FeatureGroupResult('foo', Vector {
                    FeatureResult::failed('foo->bar()'),
                    FeatureResult::pending('foo->foo()')
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
                $groupResult = new FeatureGroupResult('foo', Vector {
                    FeatureResult::pending('foo->bar()'),
                    FeatureResult::pending('foo->foo()')
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
