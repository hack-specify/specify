<?hh //partial

use hhspecify\result\FeatureResult;
use hhspecify\result\FeatureGroupResult;
use hhspecify\feature\FeatureDescription;
use hhspecify\util\ProcessingTime;
use \Exception;


describe(FeatureGroupResult::class, function() {
    describe('->getLabelGroupFeatureResults()', function() {
        beforeEach(function() {
            $this->groupResult = new FeatureGroupResult('foo', Vector {
                FeatureResult::passed(new FeatureDescription('label1', 'foo->bar() patturn1'), new ProcessingTime()),
                FeatureResult::passed(new FeatureDescription('label1', 'foo->bar() patturn2'), new ProcessingTime()),
                FeatureResult::passed(new FeatureDescription('label2', 'foo->bar() patturn1'), new ProcessingTime())
            });
        });
        it('grouping by label', function() {
            $result = $this->groupResult->getLabelGroupFeatureResults();

            $labelResult = $result->at('label1');
            expect($labelResult->count())->toBe(2);

            $labelResult = $result->at('label2');
            expect($labelResult->count())->toBe(1);
        });
    });
    describe('->isPassed()', function() {
        context('when passed', function() {
            beforeEach(function() {
                $description = new FeatureDescription('label', 'foo->bar()');
                $passedResult = FeatureResult::passed($description, new ProcessingTime());

                $this->groupResult = new FeatureGroupResult('foo', Vector {
                    $passedResult
                });
            });
            it('returns true', function() {
                $result = $this->groupResult->isPassed();
                expect($result)->toBeTrue();
            });
        });
    });
    describe('->isFailed()', function() {
        context('when failed', function() {
            beforeEach(function() {
                $description = new FeatureDescription('label', 'foo->bar()');
                $failedResult = FeatureResult::failed($description, new ProcessingTime(), new Exception('failed'));

                $this->groupResult = new FeatureGroupResult('foo', Vector {
                    $failedResult
                });
            });
            it('returns failed result', function() {
                $result = $this->groupResult->isFailed();
                expect($result)->toBeTrue();

                $result = $this->groupResult->isPassed();
                expect($result)->toBeFalse();
            });
        });
    });
    describe('->isPending()', function() {
        context('when failed', function() {
            beforeEach(function() {
                $description = new FeatureDescription('label', 'foo->bar()');
                $failedResult = FeatureResult::failed($description, new ProcessingTime(), new Exception('failed'));

                $description = new FeatureDescription('label', 'foo->foo()');
                $pendingResult = FeatureResult::failed($description, new ProcessingTime(), new Exception('failed'));

                $this->groupResult = new FeatureGroupResult('foo', Vector {
                    $failedResult,
                    $pendingResult
                });
            });
            it('returns false', function() {
                $result = $this->groupResult->isPending();
                expect($result)->toBeFalse();

                $result = $this->groupResult->isPassed();
                expect($result)->toBeFalse();

                $result = $this->groupResult->isFailed();
                expect($result)->toBeTrue();
            });
        });
        context('when pending', function() {
            beforeEach(function() {
                $description = new FeatureDescription('label', 'foo->bar()');
                $pendingResult1 = FeatureResult::pending($description);

                $description = new FeatureDescription('label', 'foo->foo()');
                $pendingResult2 = FeatureResult::pending($description);

                $this->groupResult = new FeatureGroupResult('foo', Vector {
                    $pendingResult1,
                    $pendingResult2
                });
            });
            it('returns true', function() {
                $result = $this->groupResult->isPending();
                expect($result)->toBeTrue();

                $result = $this->groupResult->isPassed();
                expect($result)->toBeTrue();

                $result = $this->groupResult->isFailed();
                expect($result)->toBeFalse();
            });
        });
    });
});
