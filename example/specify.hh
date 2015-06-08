<?hh //partial

use specify\Specify;
use specify\config\ConfigBuilder;
use specify\reporter\SpecificationReporter;


Specify::configure((ConfigBuilder $builder) ==> {

    $package = shape(
        'namespace' => 'specify\\example\\',
        'packageDirectory' => __DIR__
    );

    $builder->package($package)
        ->featureReporter(new SpecificationReporter());

});
