<?hh //partial

use specify\collector\SpecificationFileCollector;

describe(SpecificationFileCollector::class, function() {
    describe('->collectFrom()', function() {
        beforeEach(function() {
            $this->collector = new SpecificationFileCollector();
        });
        it('returns the spec files', function() {
            $files = $this->collector->collectFrom(__DIR__ . '/../fixtures/specs/collector');
            expect($files->count())->toBe(3);
        });
    });
});