<?hh //strict

namespace specify\config;

use specify\Config;
use specify\LifeCycleMessageSubscriber;
use specify\specification\PackageSpecification;


class ConfigBuilder
{

    private PackageSpecification $package;
    private ExampleReporter $exampleReporter;

    public function package(Package $package) : this
    {
        $this->package = new PackageSpecification($package);
        return $this;
    }

    public function exampleReporter(ExampleReporter $exampleReporter) : this
    {
        $this->exampleReporter = $exampleReporter;
        return $this;
    }

    public function build() : Config
    {
        return new Config(shape(
            'package' => $this->package,
            'exampleReporter' => $this->exampleReporter
        ));
    }

}
