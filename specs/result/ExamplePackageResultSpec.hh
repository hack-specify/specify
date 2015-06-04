<?hh //partial

use specify\result\ExampleResult;
use specify\result\ExampleGroupResult;
use specify\result\ExamplePackageResult;
use \Exception;


describe(ExamplePackageResult::class, function() {
    describe('->isPassed()', function() {
        context('when passed', function() {
            it('returns true', function() {
                $group1 = new ExampleGroupResult('foo', Vector {
                    ExampleResult::passed('foo->bar()')
                });
                $group2 = new ExampleGroupResult('bar', Vector {
                    ExampleResult::passed('bar->bar()')
                });

                $packageResult = new ExamplePackageResult('package', ImmVector {
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
                $group1 = new ExampleGroupResult('foo', Vector {
                    ExampleResult::failed('foo->bar()')
                });
                $group2 = new ExampleGroupResult('bar', Vector {
                    ExampleResult::pending('bar->bar()')
                });

                $packageResult = new ExamplePackageResult('package', ImmVector {
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
                $group1 = new ExampleGroupResult('foo', Vector {
                    ExampleResult::pending('foo->bar()')
                });
                $group2 = new ExampleGroupResult('bar', Vector {
                    ExampleResult::pending('bar->bar()')
                });

                $packageResult = new ExamplePackageResult('package', ImmVector {
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
