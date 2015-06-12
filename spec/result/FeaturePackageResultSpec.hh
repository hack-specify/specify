<?hh //partial

use hhspecify\result\FeatureResult;
use hhspecify\result\FeatureGroupResult;
use hhspecify\result\FeaturePackageResult;
use \Exception;


describe(FeaturePackageResult::class, function() {
    describe('->isPassed()', function() {
        context('when passed', function() {
            it('returns true', function() {
                $group1 = new FeatureGroupResult('foo', Vector {
                    FeatureResult::passed('foo->bar()')
                });
                $group2 = new FeatureGroupResult('bar', Vector {
                    FeatureResult::passed('bar->bar()')
                });

                $packageResult = new FeaturePackageResult('package', ImmVector {
                    $group1, $group2
                });

                $result = $packageResult->isPassed();
                expect($result)->toBeTrue();
            });
        });
    });
    describe('->isPending()', function() {
        context('when failed', function() {
            it('returns false', function() {
                $group1 = new FeatureGroupResult('foo', Vector {
                    FeatureResult::failed('foo->bar()')
                });
                $group2 = new FeatureGroupResult('bar', Vector {
                    FeatureResult::pending('bar->bar()')
                });

                $packageResult = new FeaturePackageResult('package', ImmVector {
                    $group1, $group2
                });

                $result = $packageResult->isPending();
                expect($result)->toBeFalse();

                $result = $packageResult->isPassed();
                expect($result)->toBeFalse();

                $result = $packageResult->isFailed();
                expect($result)->toBeTrue();
            });
        });
        context('when pending', function() {
            it('returns true', function() {
                $group1 = new FeatureGroupResult('foo', Vector {
                    FeatureResult::pending('foo->bar()')
                });
                $group2 = new FeatureGroupResult('bar', Vector {
                    FeatureResult::pending('bar->bar()')
                });

                $packageResult = new FeaturePackageResult('package', ImmVector {
                    $group1, $group2
                });

                $result = $packageResult->isPending();
                expect($result)->toBeTrue();

                $result = $packageResult->isPassed();
                expect($result)->toBeTrue();

                $result = $packageResult->isFailed();
                expect($result)->toBeFalse();
            });
        });
    });
});
