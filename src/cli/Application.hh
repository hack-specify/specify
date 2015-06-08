<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\cli;

use specify\Specify;
use specify\notifier\DefaultLifeCycleNotifier;
use specify\feature\FeaturePackage;
use specify\result\FeaturePackageResult;
use specify\collector\FeatureGroupCollector;


class Application
{

    public function run(Argument $argv) : void
    {
        $configFile = $argv->getConfigFile();
        $loadConfigFile = getcwd() . '/' . $configFile;

        include_once $loadConfigFile;

        $config = Specify::currentConfig();

        $lifeCycleNotifier = new DefaultLifeCycleNotifier(ImmVector {
            $config->getFeatureReporter()
        });

        $collector = new FeatureGroupCollector();

        $package = $config->getPackage();
        $groups = $collector->collectFrom($package);

        $package = new FeaturePackage($package->getNamespace(), $groups);
        $packageResult = $package->verify($lifeCycleNotifier);

        $this->shutdown($packageResult);
    }

    private function shutdown(FeaturePackageResult $result) : void
    {
        if ($result->isPassed()) {
            exit(ApplicationResultStatus::Passed);
        }
        exit(ApplicationResultStatus::Failed);
    }

}
