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
use specify\AttributeType;
use specify\FeatureSpecification;
use specify\notifier\FeatureNotifier;
use specify\result\FeatureResult;
use specify\util\StopWatch;
use \ReflectionMethod;
use \Exception;


class Feature implements FeatureSpecification<FeatureResult, FeatureNotifier>
{

    private string $description = 'example description empty';
    private StopWatch $stopWatch;
    private FeatureVerifierBuilder $verifierBuilder;

    public function __construct(
        private Specification $target,
        private ReflectionMethod $method
    )
    {
        $this->verifierBuilder = new FeatureVerifierBuilder();
        $this->init();
    }

    public function verify(FeatureNotifier $notifier) : FeatureResult
    {
        $notifier->featureStart($this->description);

        $result = $this->verifyExample($notifier);

        $notifier->featureFinish($result);

        return $result;
    }

    private function init() : void
    {
        $this->stopWatch = new StopWatch();

        $attributeValues = $this->method->getAttribute((string) AttributeType::Feature);

        if ($attributeValues === null) {
            return;
        }
        $this->description = (string) $attributeValues[0];
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
            $result = FeatureResult::passed($this->description, $totalTime);
        } else {
            $result = FeatureResult::failed($this->description, $totalTime, $failedReasonException);
        }

        return $result;
    }

}
