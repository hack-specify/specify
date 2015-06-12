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
use hhspecify\event\FeatureGroupStart;
use hhspecify\event\FeatureFinish;
use hhspecify\event\FeatureGroupFinish;
use hhspecify\event\FeaturePackageFinish;
use hhspecify\result\FeatureResult;
use hhspecify\io\ConsoleOutput;
use hhspecify\io\Console;


final class SpecificationReporter implements LifeCycleMessageSubscriber
{

    private string $indent = '';
    private int $indentLevel = 0;

    public function __construct(
        private Console $writer = new ConsoleOutput()
    )
    {
    }

    public function receive(LifeCycleEvent $event) : void
    {
        if ($event instanceof FeaturePackageStart) {
            $this->onPackageStart($event);
        } else if ($event instanceof FeatureGroupStart) {
            $this->onGroupStart($event);
        } else if ($event instanceof FeatureGroupFinish) {
            $this->onGroupFinish($event);
        }
    }

    private function onPackageStart(FeaturePackageStart $event) : void
    {
        $this->writer->writeln("\nPackage: %s\n", $event->getDescription());
    }

    private function onGroupStart(FeatureGroupStart $event) : void
    {
        $this->nextLevel();
        $this->writer->write($this->indent . "<white>%s</white>\n", $event->getDescription());
    }

    private function onGroupFinish(FeatureGroupFinish $event) : void
    {
        $result = $event->getLabelGroupFeatureResults();

        foreach ($result->toArray() as $label => $featureResults) {
            $this->nextLevel();
            $this->writeFeatureLabel($label);
            $this->writeFeatureResults($featureResults);
            $this->parentLevel();
        }
        $this->writer->writeln("");
        $this->parentLevel();
    }

    private function writeFeatureLabel(string $label) : void
    {
        $this->writer->writeln($this->indent . $label);
    }

    private function writeFeatureResults(FeatureResultCollection $results) : void
    {
        $this->nextLevel();

        foreach ($results->items() as $result) {
            $format = "<green>✓</green> <white>%s</white>";

            if ($result->isFailed()) {
                $format = "  <red>%s</red>";
            } else if ($result->isPending()) {
                $format = "  <lightCyan>%s</lightCyan>";
            }
            $this->writer->writeln($this->indent . $format, $result->getDescription());
        }

        $this->parentLevel();
    }

    private function nextLevel() : void
    {
        $this->indentLevel++;
        $this->indent = str_pad("", $this->indentLevel * 2, " ");
    }

    private function parentLevel() : void
    {
        $this->indentLevel--;
        $this->indent = str_pad("", $this->indentLevel * 2, " ");
    }

}
