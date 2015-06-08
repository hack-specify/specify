<?hh //partial

use specify\feature\PendingFeature;
use specify\feature\FeatureDescription;
use specify\fixtures\example\FeatureExample;
use specify\notifier\NullNotifier;
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

                expect($result->getDescription())->toBeAnInstanceOf(FeatureDescription::class);
                expect($result->isPassed())->toBeFalse();
                expect($result->isFailed())->toBeFalse();
                expect($result->isPending())->toBeTrue();
            });
        });
    });
});
