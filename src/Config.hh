<?hh //strict

namespace specify;

use specify\specification\PackageSpecification;


class Config
{

    const string FILE_NAME = 'specify.hh';

    private PackageSpecification $package;
    private ExampleReporter $exampleReporter;

    public function __construct(ConfigOptions $config)
    {
        $this->package = $config['package'];
        $this->exampleReporter = $config['exampleReporter'];
    }

    public function getPackage() : PackageSpecification
    {
        return $this->package;
    }

    public function getExampleReporter() : ExampleReporter
    {
        return $this->exampleReporter;
    }

}
