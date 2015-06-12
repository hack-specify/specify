<?hh //partial

use hhspecify\result\FeatureResult;
use hhspecify\feature\FeatureDescription;
use \Exception;


describe(FeatureResult::class, function() {
    describe('->passed()', function() {
        beforeEach(function() {
            $description = new FeatureDescription('foo');
            $this->exampleResult = FeatureResult::passed($description);
        });
        it('returns passed result', function() {
            $result = $this->exampleResult->isPassed();
            expect($result)->toBeTrue();

            $result = $this->exampleResult->isFailed();
            expect($result)->toBeFalse();

            $result = $this->exampleResult->isPending();
            expect($result)->toBeFalse();
        });
    });
    describe('->failed()', function() {
        beforeEach(function() {
            $description = new FeatureDescription('foo');
            $this->exampleResult = FeatureResult::failed($description, new Exception('failed!!'));
        });
        it('returns failed result', function() {
            $result = $this->exampleResult->isFailed();
            expect($result)->toBeTrue();

            $result = $this->exampleResult->isPassed();
            expect($result)->toBeFalse();

            $result = $this->exampleResult->isPending();
            expect($result)->toBeFalse();
        });
    });
    context('->pending()', function() {
        beforeEach(function() {
            $description = new FeatureDescription('foo');
            $this->exampleResult = FeatureResult::pending($description);
        });
        it('returns pending result', function() {
            $result = $this->exampleResult->isFailed();
            expect($result)->toBeFalse();

            $result = $this->exampleResult->isPassed();
            expect($result)->toBeFalse();

            $result = $this->exampleResult->isPending();
            expect($result)->toBeTrue();
        });
    });
});
