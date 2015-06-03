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

use \Generator;

interface Collector<Tt, Tk, Tv>
{
    public function collectFrom(Tt $target) : Generator<Tk, Tv, void>;
}
