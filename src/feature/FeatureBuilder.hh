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


class FeatureBuilder
{

    private Vector<(function(): void)> $blocks = Vector {};

    public function setup((function(): void) $setup) : this
    {
        return $this->append($setup);
    }

    public function when((function(): void) $when) : this
    {
        return $this->append($when);
    }

    public function then((function(): void) $then) : void
    {
        $this->append($then);
    }

    public function expect((function(): void) $expect) : void
    {
        $this->append($expect);
    }

    private function append((function(): void) $block) : this
    {
        $this->blocks->add($block);
        return $this;
    }

    public function verify() : void
    {
        $blocks = $this->blocks->items();

        foreach ($blocks as $block) {
            $block();
        }
    }

}
