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
use specify\event\FeatureGroupStart;
use specify\event\FeatureGroupFinish;
use specify\event\FeaturePackageFinish;
use specify\io\ConsoleOutput;
use specify\io\Console;


final class SpecificationReporter implements LifeCycleMessageSubscriber
{

    private int $indentLevel = 0;
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
        if ($event instanceof FeaturePackageStart) {
            $this->onPackageStart($event);
        } else if ($event instanceof FeatureGroupStart) {
            $this->onGroupStart($event);
        } else if ($event instanceof FeatureGroupFinish) {
            $this->onGroupFinish($event);
        } else if ($event instanceof FeaturePackageFinish) {
            $this->onPackageFinish($event);
        }
    }

    private function onPackageStart(FeaturePackageStart $event) : void
    {
        $this->writer->writeln("\nPackage: %s\n", $event->getDescription());
        $this->indentLevel++;
    }

    private function onGroupStart(FeatureGroupStart $event) : void
    {
        $indentSpace = str_pad("", $this->indentLevel * 2, " ");

        $this->writer->write($indentSpace . "<white>%s</white>\n", $event->getDescription());
        $this->indentLevel++;
    }

    private function onGroupFinish(FeatureGroupFinish $event) : void
    {
        $result = $event->getFeatureGroupResult();
        $featureResults = $result->getFeatureResults();

        $indentSpace = str_pad("", $this->indentLevel * 2, " ");

        foreach ($featureResults as $featureResult) {
            $format = "<green>✓</green> <white>%s</white>\n";

            if ($featureResult->isFailed()) {
                $format = "  <red>%s</red>\n";
            } else if ($featureResult->isPending()) {
                $format = "  <lightCyan>%s</lightCyan>\n";
            }
            $this->writer->write($indentSpace . $format, $featureResult->getDescription());
        }

        $this->writer->writeln("");
        $this->indentLevel--;
    }

    private function onPackageFinish(FeaturePackageFinish $event) : void
    {
        $event->sendTo($this->reporter);
    }

}
