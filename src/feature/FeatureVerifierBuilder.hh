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

use specify\Builder;
use \Exception;


class FeatureVerifierBuilder implements Builder<FeatureVerifier>
{

    public function __construct(
        private (function():void) $setup = () ==> {},
        private (function():void) $when = () ==> {},
        private (function():void) $then = () ==> {},
        private (function(Exception):void) $thenThrown = (Exception $exception) ==> {},
        private (function():void) $cleanup = () ==> {}
    )
    {
    }

    public function setup((function(): void) $setup) : this
    {
        $this->setup = $setup;
        return $this;
    }

    public function when((function(): void) $when) : this
    {
        $this->when = $when;
        return $this;
    }

    public function then((function(): void) $then) : this
    {
        $this->then = $then;
        return $this;
    }

    public function thenThrown((function(Exception): void) $then) : this
    {
        $this->thenThrown = $then;
        return $this;
    }

    public function cleanup((function(): void) $cleanup) : this
    {
        $this->cleanup = $cleanup;
        return $this;
    }

    public function build() : FeatureVerifier
    {
        return new FeatureVerifier(
            $this->setup,
            $this->when,
            $this->then,
            $this->cleanup
        );
    }
/*
    public function __set(string $name, mixed $value) : void
    {
        if (method_exists($this, $name)) {
            call_user_func_array([ $this, $name ], [ $value ]);
        }
    }
*/
}
