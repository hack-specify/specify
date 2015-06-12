<?hh //partial

use hhspecify\result\FeatureResult;
use hhspecify\result\FeatureGroupResult;
use hhspecify\result\FeaturePackageResult;
use hhspecify\feature\FeatureDescription;
use \Exception;


describe(FeaturePackageResult::class, function() {
    describe('->isPassed()', function() {
        context('when passed', function() {
            beforeEach(function() {
                $description1 = new FeatureDescription('l1', 'foo->bar()');
                $description2 = new FeatureDescription('l2', 'bar->bar()');

                $group1 = new FeatureGroupResult('foo', Vector {
                    FeatureResult::passed($description1)
                });

                $group2 = new FeatureGroupResult('bar', Vector {
                    FeatureResult::passed($description2)
                });

                $this->packageResult = new FeaturePackageResult('package', ImmVector {
                    $group1, $group2
                });
            });
            it('returns true', function() {
                $result = $this->packageResult->isPassed();
                expect($result)->toBeTrue();
            });
        });
    });
    describe('->isPending()', function() {
        context('when failed', function() {
            beforeEach(function() {
                $description1 = new FeatureDescription('l1', 'foo->bar()');
                $description2 = new FeatureDescription('l2', 'bar->bar()');

                $group1 = new FeatureGroupResult('foo', Vector {
                    FeatureResult::failed($description1)
                });
                $group2 = new FeatureGroupResult('bar', Vector {
                    FeatureResult::pending($description2)
                });

                $this->packageResult = new FeaturePackageResult('package', ImmVector {
                    $group1, $group2
                });
            });
            it('returns false', function() {
                $result = $this->packageResult->isPending();
                expect($result)->toBeFalse();

                $result = $this->packageResult->isPassed();
                expect($result)->toBeFalse();

                $result = $this->packageResult->isFailed();
                expect($result)->toBeTrue();
            });
        });
        context('when pending', function() {
            beforeEach(function() {
                $description1 = new FeatureDescription('l1', 'foo->bar()');
                $description2 = new FeatureDescription('l2', 'bar->bar()');

                $group1 = new FeatureGroupResult('foo', Vector {
                    FeatureResult::pending($description1)
                });
                $group2 = new FeatureGroupResult('bar', Vector {
                    FeatureResult::pending($description2)
                });

                $this->packageResult = new FeaturePackageResult('package', ImmVector {
                    $group1, $group2
                });
            });
            it('returns true', function() {
                $result = $this->packageResult->isPending();
                expect($result)->toBeTrue();

                $result = $this->packageResult->isPassed();
                expect($result)->toBeTrue();

                $result = $this->packageResult->isFailed();
                expect($result)->toBeFalse();
            });
        });
    });
});
