<?hh //partial

use hhspecify\HHSpecify;
use hhspecify\config\ConfigBuilder;
use hhspecify\reporter\SpecificationReporter;


HHSpecify::configure((ConfigBuilder $builder) ==> {

    $package = shape(
        'namespace' => 'hhspecify\\example\\',
        'packageDirectory' => __DIR__
    );

    $builder->package($package)
        ->featureReporter(new SpecificationReporter());

});
