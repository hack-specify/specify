<?hh //partial

use specify\LifeCycleNotifier;
use specify\LifeCycleMessageSubscriber;
use specify\config\ConfigBuilder;
use specify\specification\PackageSpecification;
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
                ->exampleReporter($this->reporter)
                ->build();

            $package = $config->getPackage();
            expect($package)->toBeAnInstanceOf(PackageSpecification::class);

            $reporter = $config->getExampleReporter();
            expect($reporter)->toBeAnInstanceOf(LifeCycleMessageSubscriber::class);
        });
    });
});
