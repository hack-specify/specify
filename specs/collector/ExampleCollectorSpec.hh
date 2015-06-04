<?hh //partial

use specify\collector\ExampleCollector;
use specify\fixtures\example\Example;


describe(ExampleCollector::class, function() {
    describe('->collectFrom()', function() {
        beforeEach(function() {
            $this->exampleGroup = new Example();
            $this->collector = new ExampleCollector();
        });
        it('returns the example objects', function() {
            $examples = $this->collector->collectFrom($this->exampleGroup);
            expect($examples->count())->toBe(3);
        });
    });
});
