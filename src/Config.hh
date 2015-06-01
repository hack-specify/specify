<?hh //strict

namespace specify;

use specify\specification\PackageSpecification;


class Config
{

    private PackageSpecification $package;
    private LifeCycleMessageSubscriber $reporter;

    public function __construct(ConfigOptions $config)
    {
        $this->package = $config['package'];
        $this->reporter = $config['reporter'];
    }

    public function getPackage() : PackageSpecification
    {
        return $this->package;
    }

    public function getReporter() : LifeCycleMessageSubscriber
    {
        return $this->reporter;
    }

}
