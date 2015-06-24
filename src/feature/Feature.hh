<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\feature;

use hhspecify\Specification;
use hhspecify\AttributeType;
use hhspecify\FeatureSpecification;
use hhspecify\notifier\FeatureNotifier;
use hhspecify\result\FeatureResult;
use hhspecify\util\StopWatch;
use \ReflectionMethod;
use \Exception;


class Feature implements FeatureSpecification<FeatureResult, FeatureNotifier>
{

    private FeatureDescription $description;
    private StopWatch $stopWatch;
    private FeatureVerifierBuilder $verifierBuilder;

    public function __construct(
        private Specification $target,
        private ReflectionMethod $method
    )
    {
        $this->verifierBuilder = new FeatureVerifierBuilder();
        $this->stopWatch = new StopWatch();
        $this->description = new FeatureDescription();
        $this->setup();
    }

    public function verify(FeatureNotifier $notifier) : FeatureResult
    {
        $notifier->featureStart($this->description);

        $result = $this->verifyExample($notifier);

        $notifier->featureFinish($result);

        return $result;
    }

    private function setup() : void
    {
        $values = $this->method->getAttribute((string) AttributeType::Feature);

        if ($values === null) {
            return;
        }
        $description = (string) $values[0];

        $name = $this->method->getName();
        $detailDescription = str_replace('_', ' ', $name);

        $this->description = new FeatureDescription($description, $detailDescription);
    }

    private function getDescription() : FeatureDescription
    {
        return $this->description;
    }

    private function verifyExample(FeatureNotifier $notifier) : FeatureResult
    {
        $failedReasonException = null;

        $this->stopWatch->start();
        try {
            $this->method->invoke($this->target, $this->verifierBuilder);

            $verifier = $this->verifierBuilder->build();
            $verifier->verify($notifier);
        } catch (Exception $exception) {
            $failedReasonException = $exception;
        }
        $this->stopWatch->stop();

        $result = null;
        $totalTime = $this->stopWatch->getResult();

        if ($failedReasonException === null) {
            $result = FeatureResult::passed($this->getDescription(), $totalTime);
        } else {
            $result = FeatureResult::failed($this->getDescription(), $totalTime, $failedReasonException);
        }

        return $result;
    }

}
