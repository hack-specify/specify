<?hh //partial

use specify\specification\PackageSpecification;
use \ReflectionClass;

describe(PackageSpecification::class, function() {
    describe('->resolve()', function() {
        beforeEach(function() {
            $package = Pair { 'specify\\fixtures\\', realpath(__DIR__ . '/../fixtures/specs') };
            $this->specification = new PackageSpecification($package);
        });
        it('returns the ReflectionClass instance of resolve class', function() {
            $file = realpath(__DIR__ . '/../fixtures/specs/A.hh');
            $result = $this->specification->resolve($file);

            expect($result)->toBeAnInstanceOf(ReflectionClass::class);
        });
    });
});
