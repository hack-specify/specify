<?hh //partial

use specify\collector\ExampleGroupCollector;
use specify\specification\PackageSpecification;
use specify\fixtures\A;
use specify\fixtures\example\B;


describe(ExampleGroupCollector::class, function() {
    describe('->collectFrom()', function() {
        beforeEach(function() {
            $package = Pair { 'specify\\fixtures\\', realpath(__DIR__ . '/../fixtures/specs') };

            $this->spec = new PackageSpecification($package);
            $this->collector = new ExampleGroupCollector();
        });
        it('returns the example group objects', function() {
            $results = Vector {};
            $exampleGroups = $this->collector->collectFrom($this->spec);

            foreach ($exampleGroups as $exampleGroup) {
                $results->add($exampleGroup);
            }

            $group1 = $results->at(0);
            $group2 = $results->at(1);

            expect($group1->getDescription())->toBe(A::class);
            expect($group2->getDescription())->toBe(B::class);
        });
    });
});
