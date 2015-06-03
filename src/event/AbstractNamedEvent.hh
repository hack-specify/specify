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
use specify\LifeCycleMessageSubscriber;
use \DateTime;


abstract class AbstractNamedEvent implements LifeCycleEvent
{

    protected LifeCycleEventType $name;
    protected DateTime $sendAt;

    public function getName() : string
    {
        return (string) $this->name;
    }

    public function getSendAt() : DateTime
    {
        return $this->sendAt;
    }

    public function sendTo(LifeCycleMessageSubscriber $subscriber) : void
    {
        $subscriber->handle($this);
    }

}
