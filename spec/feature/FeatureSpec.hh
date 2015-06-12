<?hh //partial

use hhspecify\feature\Feature;
use hhspecify\feature\FeatureDescription;
use hhspecify\fixtures\example\FeatureExample;
use hhspecify\notifier\NullNotifier;
use \Prophecy\Prophet;
use \Prophecy\Argument;
use \Exception;


describe(Feature::class, function() {
    describe('->verify()', function() {
        context('when passed', function() {
            beforeEach(function() {
                $this->notifier = new NullNotifier();
            });
            it('returns passed result', function() {
                $target = new FeatureExample();
                $featureMethod = new ReflectionMethod($target, 'example1');

                $feature = new Feature($target, $featureMethod);
                $result = $feature->verify($this->notifier);

                expect($result->getDescription())->toBe('example1');
                expect($result->isPassed())->toBeTrue();
                expect($result->isFailed())->toBeFalse();
            });
        });
        context('when failed', function() {
            beforeEach(function() {
                $this->notifier = new NullNotifier();
            });
            it('returns passed result', function() {
                $target = new FeatureExample();
                $featureMethod = new ReflectionMethod($target, 'example3');

                $feature = new Feature($target, $featureMethod);
                $result = $feature->verify($this->notifier);

                expect($result->getDescription())->toBe('example3');
                expect($result->isPassed())->toBeFalse();
                expect($result->isFailed())->toBeTrue();
            });
        });
    });
});
