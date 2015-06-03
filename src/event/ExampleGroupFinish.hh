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

class ExampleGroupFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private ExampleGroupResult $result
    )
    {
        $this->name = LifeCycleEventType::ExampleGroupFinish;
        $this->sendAt = new DateTime();
    }

    public function getExampleCount() : int
    {
        return $this->result->getExampleCount();
    }

    public function getFailedExampleCount() : int
    {
        return $this->result->getFailedExampleCount();
    }

    public function getExampleGroupResult() : ExampleGroupResult
    {
        return $this->result;
    }

}
