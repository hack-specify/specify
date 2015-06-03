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
use specify\event\ExamplePackageStart;
use specify\event\ExampleGroupStart;
use specify\event\ExampleGroupFinish;
use specify\event\ExamplePackageFinish;


class SpecificationReporter implements LifeCycleMessageSubscriber
{

    private int $indentLevel = 0;


    public function handle(LifeCycleEvent $event) : void
    {
        if ($event instanceof ExamplePackageStart) {
            $this->onExamplePackageStart($event);
        } else if ($event instanceof ExampleGroupStart) {
            $this->onExampleGroupStart($event);
        } else if ($event instanceof ExampleGroupFinish) {
            $this->onExampleGroupFinish($event);
        } else if ($event instanceof ExamplePackageFinish) {
            $this->onExamplePackageFinish($event);
        }
    }

    public function onExamplePackageStart(ExamplePackageStart $event) : void
    {
        $this->writeln("\n%s\n\n", $event->getDescription());
        $this->indentLevel++;
    }

    public function onExampleGroupStart(ExampleGroupStart $event) : void
    {
        $this->writeWithIndent("%s\n", $event->getDescription());
        $this->indentLevel++;
    }

    public function onExampleGroupFinish(ExampleGroupFinish $event) : void
    {
        $result = $event->getExampleGroupResult();
        $exampleResults = $result->getExampleResults();

        foreach ($exampleResults as $exampleResult) {
            $status = $exampleResult->isFailed() ? 'ok' : 'ng';
            $this->writeWithIndent("%s %s\n", $status, $exampleResult->getDescription());
        }

        $this->writeln("\n");
        $this->indentLevel--;
    }

    public function onExamplePackageFinish(ExamplePackageFinish $event) : void
    {
        $this->writeln("%d example, %d failures\n",
            $event->getExampleCount(),
            $event->getFailedExampleCount()
        );
    }

    private function writeWithIndent(string $format, ...) : void
    {
        $values = func_get_args();
        $indentSpace = str_pad("", $this->indentLevel * 2, " ");

        $values[0] = $indentSpace . $format;
        echo call_user_func_array('sprintf', $values);
    }

    private function writeln(string $format, ...) : void
    {
        $values = func_get_args();
        echo call_user_func_array('sprintf', $values);
    }

}
