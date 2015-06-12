<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\cli;

use hhspecify\HHSpecify;
use hhspecify\notifier\DefaultLifeCycleNotifier;
use hhspecify\feature\FeaturePackage;
use hhspecify\result\FeaturePackageResult;
use hhspecify\collector\FeatureGroupCollector;
use hhspecify\reporter\ShutdownReporter;


class Application
{

    public function __construct(
        private FeaturePackageResult $packageResult = FeaturePackageResult::createEmptyResult()
    )
    {
    }

    public function run(Argument $argv) : void
    {
        $this->startup($argv);
        $this->doRun();
        $this->shutdown();
    }

    private function startup(Argument $argv) : void
    {
        $configFile = $argv->getConfigFile();
        $loadConfigFile = getcwd() . '/' . $configFile;

        include_once $loadConfigFile;
    }

    private function doRun() : void
    {
        $config = HHSpecify::currentConfig();

        $lifeCycleNotifier = new DefaultLifeCycleNotifier(ImmVector {
            $config->getFeatureReporter()
        });

        $collector = new FeatureGroupCollector();

        $package = $config->getPackage();
        $groups = $collector->collectFrom($package);

        $package = new FeaturePackage($package->getNamespace(), $groups);
        $packageResult = $package->verify($lifeCycleNotifier);

        $this->packageResult = $packageResult;
    }

    private function shutdown() : void
    {
        if ($this->packageResult->isPassed()) {
            exit(ApplicationResultStatus::Passed);
        }
        exit(ApplicationResultStatus::Failed);
    }

}
