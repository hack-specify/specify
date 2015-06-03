<?hh //partial

use specify\collector\ExampleGroupCollector;
use specify\specification\PackageSpecification;
use specify\fixtures\A;
use specify\fixtures\example\B;


describe(ExampleGroupCollector::class, function() {
    describe('->collectFrom()', function() {
        beforeEach(function() {
            $package = shape(
                'namespace' => 'specify\\fixtures\\',
                'packageDirectory' => realpath(__DIR__ . '/../fixtures/specs')
            );
            $this->spec = new PackageSpecification($package);
            $this->collector = new ExampleGroupCollector();
        });
        it('returns the example group objects', function() {
            $exampleGroups = $this->collector->collectFrom($this->spec);
            expect($exampleGroups->count())->toBe(2);
        });
    });
});
