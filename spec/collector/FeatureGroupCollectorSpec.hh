<?hh //partial

use hhspecify\collector\FeatureGroupCollector;
use hhspecify\specification\PackageSpecification;
use hhspecify\fixtures\A;
use hhspecify\fixtures\example\B;


describe(FeatureGroupCollector::class, function() {
    describe('->collectFrom()', function() {
        beforeEach(function() {
            $package = shape(
                'namespace' => 'hhspecify\\fixtures\\collector\\',
                'packageDirectory' => realpath(__DIR__ . '/../fixtures/spec/collector')
            );
            $this->spec = new PackageSpecification($package);
            $this->collector = new FeatureGroupCollector();
        });
        it('returns the feature group objects', function() {
            $featureGroups = $this->collector->collectFrom($this->spec);
            expect($featureGroups->count())->toBe(2);
        });
    });
});
