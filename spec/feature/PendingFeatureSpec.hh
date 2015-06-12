<?hh //partial

use hhspecify\feature\PendingFeature;
use hhspecify\feature\FeatureDescription;
use hhspecify\fixtures\example\FeatureExample;
use hhspecify\notifier\NullNotifier;
use \Exception;


describe(PendingFeature::class, function() {
    describe('->verify()', function() {
        context('when pending', function() {
            beforeEach(function() {
                $this->notifier = new NullNotifier();
            });
            it('returns pending result', function() {
                $target = new FeatureExample();
                $pendingFeatureMethod = new ReflectionMethod($target, 'example2');

                $pendingFeature = new PendingFeature($target, $pendingFeatureMethod);
                $result = $pendingFeature->verify($this->notifier);

                expect($result->getDescription())->toBe('example2');
                expect($result->isPassed())->toBeFalse();
                expect($result->isFailed())->toBeFalse();
                expect($result->isPending())->toBeTrue();
            });
        });
    });
});
