<?hh //strict

namespace specify\runner;

use specify\ExampleRunner;
use specify\LifeCycleNotifier;
use specify\SpecificationCollector;
use specify\result\ObjectBehaviorResult;
use \ReflectionClass;


class ExampleGroupRunner implements ExampleRunner
{

    private object $description;
    private object $exampleGroup;
    private BehaviorMethodCollection $examples;

    public function __construct(ReflectionClass $reflection)
    {
        $this->description = $reflection->getName();
        $this->exampleGroup = $reflection->newInstance();

        $collector = new SpecificationCollector();
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

        $result = new ObjectBehaviorResult(
            $this->description,
            $exampleResults
        );

        $notifier->specVerifyFinish($result);
    }

}
