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
use \DateTime;

class ExampleGroupStart extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private string $description
    )
    {
        $this->name = LifeCycleEventType::ExampleGroupStart;
        $this->sendAt = new DateTime();
    }

    public function getDescription() : string
    {
        return $this->description;
    }

}
