<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\feature;

use hhspecify\notifier\FeatureNotifier;
use hhspecify\FeatureSpecification;
use \Exception;


class FeatureVerifier implements FeatureSpecification<void, FeatureNotifier>
{

    public function __construct(
        private (function():void) $setup = () ==> {},
        private (function():void) $when = () ==> {},
        private (function():void) $then = () ==> {},
        private ?(function(?Exception):void) $thenThrown = null,
        private ?(function():void) $cleanup = null
    )
    {
    }

    public function verify(FeatureNotifier $notifier) : void
    {
        $thrownException = null;

        $setup = $this->setup;
        $setup();

        try {
            $when = $this->when;
            $when();
        } catch (Exception $exception) {
            $thrownException = $exception;
        }

        if ($this->thenThrown !== null) {
            $then = $this->thenThrown;
            $then($thrownException);
        } else {
            if ($thrownException !== null) {
                throw $thrownException;
            }
            $then = $this->then;
            $then();
        }

        if ($this->cleanup === null) {
            return;
        }

        $cleanup = $this->cleanup;
        $cleanup();
    }

}
