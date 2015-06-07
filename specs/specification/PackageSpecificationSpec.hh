<?hh //partial

use specify\specification\PackageSpecification;
use \ReflectionClass;

describe(PackageSpecification::class, function() {
    beforeEach(function() {
        $package = shape(
            'namespace' => 'specify\\fixtures\\',
            'packageDirectory' => realpath(__DIR__ . '/../fixtures/specs')
        );
        $this->specification = new PackageSpecification($package);
    });
    describe('->getNamespace()', function() {
        it('returns the namespace', function() {
            $result = $this->specification->getNamespace();
            expect($result)->toBe('specify\\fixtures');
        });
    });
    describe('->resolve()', function() {
        it('returns the ReflectionClass instance of resolve class', function() {
            $file = realpath(__DIR__ . '/../fixtures/specs/example/FeatureExample.hh');
            $result = $this->specification->resolve($file);

            expect($result)->toBeAnInstanceOf(ReflectionClass::class);
        });
    });
});
