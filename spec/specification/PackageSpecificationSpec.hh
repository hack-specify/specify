<?hh //partial

use hhspecify\Specification;
use hhspecify\specification\PackageSpecification;
use \ReflectionClass;

describe(PackageSpecification::class, function() {
    beforeEach(function() {
        $package = shape(
            'namespace' => 'hhspecify\\fixtures\\',
            'packageDirectory' => realpath(__DIR__ . '/../fixtures/spec')
        );
        $this->specification = new PackageSpecification($package);
    });
    describe('->getNamespace()', function() {
        it('returns the namespace', function() {
            $result = $this->specification->getNamespace();
            expect($result)->toBe('hhspecify\\fixtures');
        });
    });
    describe('->resolve()', function() {
        it('returns the instance of resolve class', function() {
            $file = realpath(__DIR__ . '/../fixtures/spec/example/FeatureExample.hh');
            $result = $this->specification->resolve($file);

            expect($result)->toBeAnInstanceOf(Specification::class);
        });
    });
});
