<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\event;

use specify\LifeCycleEvent;
use specify\LifeCycleEventType;
use specify\result\ExampleGroupResult;
use DateTime;

final class ExampleGroupFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private ExampleGroupResult $result
    )
    {
        parent::__construct(LifeCycleEventType::ExampleGroupFinish);
    }

    public function getExampleCount() : int
    {
        return $this->result->getExampleCount();
    }

    public function getFailedExampleCount() : int
    {
        return $this->result->getFailedExampleCount();
    }

    public function getProcessingTime() : float
    {
        $processingTime = $this->result->getProcessingTime();
        return $processingTime->getProcessingTime();
    }

    public function isPassed() : bool
    {
        return $this->result->isPassed();
    }

    public function isFailed() : bool
    {
        return $this->result->isFailed();
    }

    public function isPending() : bool
    {
        return $this->result->isPending();
    }

    public function getExampleGroupResult() : ExampleGroupResult
    {
        return $this->result;
    }

}
