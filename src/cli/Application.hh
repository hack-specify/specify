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
use hhspecify\io\ConsoleOutput;


class Application
{

    private Argument $argv;
    private FeaturePackageResult $packageResult;
    private ConsoleOutput $console;

    public function __construct()
    {
        $this->argv = new Argument();
        $this->packageResult = FeaturePackageResult::createEmptyResult();
        $this->console = new ConsoleOutput();
    }

    public function run(Argument $argv) : void
    {
        $this->argv = $argv;

        if ($this->isHelpMode()) {
            $this->printHelpMessage();
            return;
        }

        $this->startup();
        $this->doRun();
        $this->shutdown();
    }

    private function startup() : void
    {
        $configFile = $this->argv->getConfigFile();
        $loadConfigFile = getcwd() . '/' . $configFile;

        include_once $loadConfigFile;
    }

    private function isHelpMode() : bool
    {
        return $this->argv->hasHelpOption();
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

    private function printHelpMessage() : void
    {
        $this->console->writeln("\n<cyan>Usage:</cyan>");
        $this->console->writeln("  hhspecify [options]\n");
        $this->console->writeln("<cyan>Options:</cyan>");
        $this->console->writeln("  -c, --config=CONFIGURATION  A hack file containing hhspecify configuration");
        $this->console->writeln("  -h, --help                  Display this help message\n");
    }

}
