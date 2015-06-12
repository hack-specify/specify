<?hh //partial

use hhspecify\result\FeatureResult;
use hhspecify\result\FeatureGroupResult;
use hhspecify\result\FeaturePackageResult;
use hhspecify\event\FeaturePackageStart;
use hhspecify\event\FeatureFinish;
use hhspecify\event\FeaturePackageFinish;
use hhspecify\io\BufferWriter;
use hhspecify\io\ConsoleOutput;
use hhspecify\reporter\DotReporter;
use hhspecify\util\ProcessingTime;


describe(DotReporter::class, function() {
    describe('->handle()', function() {
        beforeEach(function() {
            $this->bufferWriter = new BufferWriter();
            $this->consoleOutput = new ConsoleOutput($this->bufferWriter);
            $this->repoter = new DotReporter($this->consoleOutput);
        });
        context('when handle example finish events', function() {
            beforeEach(function() {
                $this->events = tuple(
                    new FeatureFinish(FeatureResult::pending('foo->bar()')),
                    new FeatureFinish(FeatureResult::passed('foo->bar1()')),
                    new FeatureFinish(FeatureResult::failed('foo->bar2()')),
                    new FeatureFinish(FeatureResult::pending('bar->bar()'))
                );
            });
            it('repoter example progress', function() {
                $result = "\e[0;36mP\e[0m.\e[0;31mF\e[0m\e[0;36mP\e[0m";

                expect(() ==> {
                    foreach ($this->events as $event) {
                        $this->repoter->receive($event);
                    }
                })->toPrint($result);
            });
        });
    });
});
