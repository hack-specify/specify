<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\reporter;

use hhspecify\LifeCycleEvent;
use hhspecify\LifeCycleMessageSubscriber;
use hhspecify\event\FeaturePackageStart;
use hhspecify\event\FeatureStart;
use hhspecify\event\FeatureFinish;
use hhspecify\event\FeaturePackageFinish;
use hhspecify\io\ConsoleOutput;
use hhspecify\io\Console;


final class FailedSummaryReporter implements LifeCycleMessageSubscriber
{

    private CompositionReporter $reporter;

    public function __construct(
        private Console $writer = new ConsoleOutput()
    )
    {
        $this->reporter = new CompositionReporter(ImmVector {
            new ProcessingTimeReporter($this->writer),
            new SummaryReporter($this->writer),
            new FailedFeatureReporter($this->writer)
        });
    }

    public function receive(LifeCycleEvent $event) : void
    {
        $this->reporter->receive($event);
    }

}
