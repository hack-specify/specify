<?hh //strict

namespace specify;

use \Generator;

interface Collector<Tt, Tk, Tv>
{
    public function collectFrom(Tt $target) : Generator<Tk, Tv, void>;
}
