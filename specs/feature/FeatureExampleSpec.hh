<?hh //partial

use specify\feature\PendingFeature;
use specify\fixtures\example\Example as FixtureExample;
use specify\helper\NotifyRecorder;
use \Exception;


describe(PendingFeature::class, function() {
    describe('->verify()', function() {
        context('when pending', function() {
            beforeEach(function() {
                $this->notifier = new NotifyRecorder();
            });
            it('returns pending result', function() {
                $target = new FixtureExample();
                $pendingFeatureMethod = new ReflectionMethod($target, 'example2');

                $pendingFeature = new PendingFeature($target, $pendingFeatureMethod);
                $result = $pendingFeature->verify($this->notifier);

                expect($result->getDescription())->toBe("example2 is pending");
                expect($result->isPassed())->toBeFalse();
                expect($result->isFailed())->toBeFalse();
                expect($result->isPending())->toBeTrue();
            });
        });
    });
});
