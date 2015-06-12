<?hh //partial

use hhspecify\LifeCycleNotifier;
use hhspecify\LifeCycleMessageSubscriber;
use hhspecify\config\ConfigBuilder;
use hhspecify\specification\PackageSpecification;
use \Prophecy\Prophet;
use \Prophecy\Argument;


describe(ConfigBuilder::class, function() {
    describe('->build()', function() {
        beforeEach(function() {
            $this->prophet = new Prophet();

            $reporter = $this->prophet->prophesize(LifeCycleMessageSubscriber::class);
            $this->reporter = $reporter->reveal();

            $this->package = $package = shape(
                'namespace' => 'specify\\fixtures\\',
                'packageDirectory' => realpath(__DIR__ . '/../fixtures/specs')
            );
            $this->builder = new ConfigBuilder();
        });
        it('returns the config object', function() {
            $config = $this->builder->package($this->package)
                ->featureReporter($this->reporter)
                ->build();

            $package = $config->getPackage();
            expect($package)->toBeAnInstanceOf(PackageSpecification::class);

            $reporter = $config->getFeatureReporter();
            expect($reporter)->toBeAnInstanceOf(LifeCycleMessageSubscriber::class);
        });
    });
});
