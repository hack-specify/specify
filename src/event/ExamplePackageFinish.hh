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
use specify\result\ExamplePackageResult;
use \DateTime;


class ExamplePackageFinish extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private ExamplePackageResult $result
    )
    {
        parent::__construct(LifeCycleEventType::ExamplePackageFinish);
    }

    public function getExampleCount() : int
    {
        return $this->result->getExampleCount();
    }

    public function getFailedExampleCount() : int
    {
        return $this->result->getFailedExampleCount();
    }

    public function getExamplePackageResult() : ExamplePackageResult
    {
        return $this->result;
    }

}
