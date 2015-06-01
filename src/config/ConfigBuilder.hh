<?hh //strict

namespace specify\config;

use specify\Config;
use specify\LifeCycleMessageSubscriber;
use specify\specification\PackageSpecification;


class ConfigBuilder
{

    private PackageSpecification $package;
    private LifeCycleMessageSubscriber $reporter;

    public function package(Package $package) : this
    {
        $this->package = new PackageSpecification($package);
        return $this;
    }

    public function reporter(LifeCycleMessageSubscriber $reporter) : this
    {
        $this->reporter = $reporter;
        return $this;
    }

    public function build() : Config
    {
        return new Config(shape(
            'package' => $this->package,
            'reporter' => $this->reporter
        ));
    }

}
