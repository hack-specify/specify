<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\feature;

use specify\Specification;
use specify\LifeCycleNotifier;
use specify\FeatureSpecification;
use specify\result\FeatureGroupResult;
use specify\collector\FeatureCollector;
use specify\util\StopWatch;

use \ReflectionClass;
use \ReflectionMethod;
use \Exception;


class FeatureGroup implements FeatureSpecification<FeatureGroupResult>
{

    private string $description;
    private Specification $exampleGroup;
    private ExampleCollection $examples;
    private StopWatch $stopWatch;

    public function __construct(
        ReflectionClass $target
    )
    {
        $this->description = $target->getName();
        $this->exampleGroup = $target->newInstance();

        $collector = new FeatureCollector();
        $this->examples = $collector->collectFrom($this->exampleGroup);
        $this->stopWatch = new StopWatch();
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function getExamples() : ExampleCollection
    {
        return $this->examples;
    }

    public function verify(LifeCycleNotifier $notifier) : FeatureGroupResult
    {
        $exampleResults = Vector {};

        $notifier->featureGroupStart($this->getDescription());

        $this->stopWatch->start();

        foreach ($this->examples as $example) {
            $result = $example->verify($notifier);
            $exampleResults->add($result);
        }

        $this->stopWatch->stop();
        $totalTime = $this->stopWatch->getResult();

        $result = new FeatureGroupResult(
            $this->description,
            $exampleResults->toImmVector(),
            $totalTime
        );

        $notifier->featureGroupFinish($result);

        return $result;
    }

}
