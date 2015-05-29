<?hh //strict

namespace minitest;

use minitest\event\RunnerStart;
use minitest\event\SpecVerifyStart;
use minitest\event\SpecVerifyFinish;
use minitest\event\RunnerStop;

interface LifeCycleMessageSubscriber
{
    public function onRunnerStart(RunnerStart $event) : void;
    public function onSpecVerifyStart(SpecVerifyStart $event) : void;
    public function onSpecVerifyFinish(SpecVerifyFinish $event) : void;
    public function onRunnerStop(RunnerStop $event) : void;
}
