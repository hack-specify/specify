<?hh //partial

use specify\collector\ExampleCollector;
use specify\fixtures\A;
use specify\fixtures\example\B;


describe(ExampleCollector::class, function() {
    describe('->collectFrom()', function() {
        beforeEach(function() {
            $this->exampleGroup = new A();
            $this->collector = new ExampleCollector();
        });
        it('returns the example objects', function() {
            $examples = $this->collector->collectFrom($this->exampleGroup);
            expect($examples->count())->toBe(1);
        });
    });
});
