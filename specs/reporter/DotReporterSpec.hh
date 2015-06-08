<?hh //partial

use specify\result\FeatureResult;
use specify\result\FeatureGroupResult;
use specify\result\FeaturePackageResult;
use specify\event\FeaturePackageStart;
use specify\event\FeatureFinish;
use specify\event\FeaturePackageFinish;
use specify\io\BufferWriter;
use specify\io\ConsoleOutput;
use specify\reporter\DotReporter;
use specify\util\ProcessingTime;


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
