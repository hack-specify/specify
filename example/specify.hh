<?hh //partial

use specify\Specify;
use specify\config\ConfigBuilder;
use specify\reporter\SpecificationReporter;


Specify::configure((ConfigBuilder $builder) ==> {

    $package = Pair {
        'specify\\example\\',
        __DIR__
    };

    $builder->package($package)
        ->exampleReporter(new SpecificationReporter());

});
