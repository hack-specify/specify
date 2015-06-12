<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\event;

use hhspecify\LifeCycleEvent;
use hhspecify\LifeCycleEventType;
use hhspecify\result\FeatureResult;
use hhspecify\feature\FeatureDescription;


final class FeatureFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private FeatureResult $result
    )
    {
        parent::__construct(LifeCycleEventType::ExampleFinish);
    }

    public function getLabel() : string
    {
        return $this->result->getLabel();
    }

    public function getDescription() : string
    {
        return $this->result->getDescription();
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

}
