<?hh //strict

namespace specify\runner;

use specify\ExampleRunner;
use specify\LifeCycleNotifier;


class PackageExampleRunner implements ExampleRunner
{

    public function __construct(
        private ExampleGroupRunnerCollection $exampleGroups
    )
    {
    }

    public function run(LifeCycleNotifier $notifier) : void
    {
        $notifier->verifyStart();

        foreach ($this->exampleGroups as $exampleGroup) {
            $exampleGroup->run($notifier);
        }

        $notifier->verifyFinish();
    }

}
