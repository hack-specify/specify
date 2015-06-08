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

use specify\LifeCycleNotifier;
use specify\FeatureSpecification;


class FeatureVerifier implements FeatureSpecification<void>
{

    public function __construct(
        private (function():void) $setup = () ==> {},
        private (function():void) $when = () ==> {},
        private (function():void) $then = () ==> {},
        private (function():void) $cleanup = () ==> {}
    )
    {
    }

    public function verify(LifeCycleNotifier $notifier) : void
    {
        $blocks = [
            $this->setup,
            $this->when,
            $this->then,
            $this->cleanup
        ];

        foreach ($blocks as $block) {
            $block();
        }
    }

}
