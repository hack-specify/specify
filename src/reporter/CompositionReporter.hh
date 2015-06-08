<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\reporter;

use specify\LifeCycleEvent;
use specify\LifeCycleMessageSubscriber;


final class CompositionReporter implements LifeCycleMessageSubscriber
{

    public function __construct(
        private ReporterCollection $reporters = ImmVector {}
    )
    {
    }

    public function receive(LifeCycleEvent $event) : void
    {
        foreach ($this->reporters as $reporter) {
            $event->sendTo($reporter);
        }
    }

}
