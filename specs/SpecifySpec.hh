<?hh //partial

use specify\Specify;
use specify\config\ConfigBuilder;
use specify\LifeCycleNotifier;
use specify\LifeCycleMessageSubscriber;
use specify\specification\PackageSpecification;
use \Prophecy\Prophet;
use \Prophecy\Argument;


describe(Specify::class, function() {
    describe('->configure()', function() {
        beforeEach(function() {
            $this->prophet = new Prophet();

            $reporter = $this->prophet->prophesize(LifeCycleMessageSubscriber::class);
            $this->reporter = $reporter->reveal();

            $this->package = shape(
                'namespace' => 'specify\\fixtures\\',
                'packageDirectory' => realpath(__DIR__ . '/../fixtures/specs')
            );
        });
        it('configure the settings for specify', function() {
            Specify::configure((ConfigBuilder $builder) ==> {

                $builder->package($this->package)
                    ->exampleReporter($this->reporter);

            });
            $config = Specify::currentConfig();

            $package = $config->getPackage();
            expect($package)->toBeAnInstanceOf(PackageSpecification::class);

            $reporter = $config->getExampleReporter();
            expect($reporter)->toBeAnInstanceOf(LifeCycleMessageSubscriber::class);
        });
    });
});
