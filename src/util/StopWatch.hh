<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\util;


class StopWatch
{

    private float $startAt = 0.0;

    public function start() : void
    {
        $this->startAt = (float) microtime(true);
    }

    public function stop() : ProcessingTime
    {
        $stopAt = (float) microtime(true);
        $processingTime = $stopAt - $this->startAt;

        $result = new ProcessingTime(
            $this->startAt,
            $stopAt,
            $processingTime
        );

        return $result;
    }

}
