<?hh //partial

use hhspecify\HHSpecify;
use hhspecify\config\ConfigBuilder;
use hhspecify\LifeCycleNotifier;
use hhspecify\LifeCycleMessageSubscriber;
use hhspecify\specification\PackageSpecification;
use \Prophecy\Prophet;
use \Prophecy\Argument;


describe(HHSpecify::class, function() {
    describe('->configure()', function() {
        beforeEach(function() {
            $this->prophet = new Prophet();

            $reporter = $this->prophet->prophesize(LifeCycleMessageSubscriber::class);
            $this->reporter = $reporter->reveal();

            $this->package = shape(
                'namespace' => 'specify\\fixtures\\',
                'packageDirectory' => realpath(__DIR__ . '/../fixtures/spec')
            );
        });
        it('configure the settings for specify', function() {
            HHSpecify::configure((ConfigBuilder $builder) ==> {

                $builder->package($this->package)
                    ->featureReporter($this->reporter);

            });
            $config = HHSpecify::currentConfig();

            $package = $config->getPackage();
            expect($package)->toBeAnInstanceOf(PackageSpecification::class);

            $reporter = $config->getFeatureReporter();
            expect($reporter)->toBeAnInstanceOf(LifeCycleMessageSubscriber::class);
        });
    });
});
