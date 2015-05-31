<?hh //strict

namespace specify\example;

use specify\Example;
use specify\result\ExampleGroupResult;
use specify\collector\ExampleCollector;
use \ReflectionClass;
use \ReflectionMethod;
use \Exception;


class ExampleGroup implements Example<ExampleGroupResult>
{

    private string $description;
    private object $exampleGroup;
    private MethodExampleCollection $examples;

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

    public function getExamples() : MethodExampleCollection
    {
        return $this->examples;
    }

    public function verify() : ExampleGroupResult
    {
    }

}
