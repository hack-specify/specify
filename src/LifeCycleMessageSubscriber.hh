<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify;

use specify\event\RunnerStart;
use specify\event\SpecVerifyStart;
use specify\event\SpecVerifyFinish;
use specify\event\RunnerStop;

interface LifeCycleMessageSubscriber
{
    public function receive(LifeCycleEvent $event) : void;
}
