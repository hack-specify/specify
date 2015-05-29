<?hh //partial

use specify\specification\PackageSpecification;
use specify\specification\ObjectSpecificationCollector;
use specify\fixtures\A;
use specify\fixtures\example\B;


describe(ObjectSpecificationCollector::class, function() {
    describe('->collectFrom()', function() {
        beforeEach(function() {
            $package = Pair { 'specify\\fixtures\\', realpath(__DIR__ . '/../fixtures/specs') };

            $this->spec = new PackageSpecification($package);
            $this->collector = new ObjectSpecificationCollector();
        });
        it('returns the specification objects', function() {
            $specResults = Vector {};
            $collectSpecs = $this->collector->collectFrom($this->spec);

            foreach ($collectSpecs as $collectSpec) {
                $specResults->add($collectSpec);
            }

            $spec1 = $specResults->at(0);
            $spec2 = $specResults->at(1);

            expect($spec1)->toBeAnInstanceOf(A::class);
            expect($spec2)->toBeAnInstanceOf(B::class);
        });
    });
});
