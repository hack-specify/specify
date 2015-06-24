<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify;

use hhspecify\event\RunnerStart;
use hhspecify\event\SpecVerifyStart;
use hhspecify\event\SpecVerifyFinish;
use hhspecify\event\RunnerStop;

interface LifeCycleMessageSubscriber
{
    public function receive(LifeCycleEvent $event) : void;
}
