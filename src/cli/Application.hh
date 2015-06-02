<?hh //strict

namespace specify\cli;

use specify\Specify;
use specify\DefaultLifeCycleNotifier;
use specify\example\ExamplePackage;
use specify\result\ExamplePackageResult;
use specify\collector\ExampleGroupCollector;


class Application
{

    public function run(Argument $argv) : void
    {
        $configFile = $argv->getConfigFile();
        $loadConfigFile = getcwd() . '/' . $configFile;

        include_once $loadConfigFile;

        $config = Specify::currentConfig();

        $lifeCycleNotifier = new DefaultLifeCycleNotifier(ImmVector {
            $config->getExampleReporter()
        });

        $collector = new ExampleGroupCollector();

        $package = $config->getPackage();
        $groups = $collector->collectFrom($package);

        $shuffleGroup = Vector {};

        foreach ($groups as $group) {
            $shuffleGroup->add($group);
        }
        $shuffleGroup->shuffle();

        $package = new ExamplePackage($package->getNamespace(), $shuffleGroup->toImmVector());
        $packageResult = $package->verify($lifeCycleNotifier);

        $this->shutdown($packageResult);
    }

    private function shutdown(ExamplePackageResult $result) : void
    {
        $success = 0;

        if ($result->isFailed()) {
            exit($success);
        }
        exit(1);
    }

}
