<?hh //strict

namespace specify\example;

use specify\LifeCycleNotifier;
use specify\SpecificationExample;
use specify\result\ExampleGroupResult;
use specify\collector\ExampleCollector;

use \ReflectionClass;
use \ReflectionMethod;
use \Exception;


class ExampleGroup implements SpecificationExample<ExampleGroupResult>
{

    private string $description;
    private object $exampleGroup;
    private ExampleCollection $examples;

    public function __construct(
        ReflectionClass $target
    )
    {
        $this->description = $target->getName();
        $this->exampleGroup = $target->newInstance();

        $collector = new ExampleCollector();
        $this->examples = $collector->collectFrom($this->exampleGroup);
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function getExamples() : ExampleCollection
    {
        return $this->examples;
    }

    public function verify(LifeCycleNotifier $notifier) : ExampleGroupResult
    {
        $exampleResults = Vector {};

        $notifier->exampleGroupStart();

        foreach ($this->examples as $example) {
            $result = $example->verify($notifier);
            $exampleResults->add($result);
        }

        $result = new ExampleGroupResult(
            $this->description,
            $exampleResults
        );

        $notifier->exampleGroupFinish($result);

        return $result;
    }

}
