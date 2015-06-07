<?hh //partial

use specify\collector\FeatureCollector;
use specify\fixtures\example\Example;


describe(FeatureCollector::class, function() {
    describe('->collectFrom()', function() {
        beforeEach(function() {
            $this->exampleGroup = new Example();
            $this->collector = new FeatureCollector();
        });
        it('returns the example objects', function() {
            $examples = $this->collector->collectFrom($this->exampleGroup);
            expect($examples->count())->toBe(3);
        });
    });
});
