<?hh //partial

use specify\collector\FeatureCollector;
use specify\fixtures\example\FeatureExample;


describe(FeatureCollector::class, function() {
    describe('->collectFrom()', function() {
        beforeEach(function() {
            $this->featureGroup = new FeatureExample();
            $this->collector = new FeatureCollector();
        });
        it('returns the example objects', function() {
            $features = $this->collector->collectFrom($this->featureGroup);
            expect($features->count())->toBe(3);
        });
    });
});
