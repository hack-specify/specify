<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\reporter;

use specify\LifeCycleEvent;
use specify\LifeCycleMessageSubscriber;
use specify\event\FeaturePackageStart;
use specify\event\FeatureStart;
use specify\event\FeatureFinish;
use specify\event\FeaturePackageFinish;
use specify\io\ConsoleOutput;
use specify\io\Console;


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
