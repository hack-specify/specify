<?hh //strict

namespace specify\runner;

use specify\ExampleRunner;
use specify\LifeCycleNotifier;
use specify\collector\ExampleCollector;
use specify\result\ExampleGroupResult;
use \ReflectionClass;


class ExampleGroupRunner implements ExampleRunner
{

    private string $description;
    private object $exampleGroup;
    private MethodExampleCollection $examples;

    public function __construct(ReflectionClass $reflection)
    {
        $this->description = $reflection->getName();
        $this->exampleGroup = $reflection->newInstance();

        $collector = new ExampleCollector();
        $this->examples = $collector->collectFrom($this->exampleGroup);
    }

    public function run(LifeCycleNotifier $notifier) : void
    {
        $exampleResults = Vector {};

        $notifier->specVerifyStart();

        foreach ($this->examples as $example) {
            $result = $example->verify();
            $exampleResults->add($result);
        }

        $result = new ExampleGroupResult(
            $this->description,
            $exampleResults
        );

        $notifier->specVerifyFinish($result);
    }

}
