<?hh //partial

use specify\result\ExampleResult;
use specify\result\ExampleGroupResult;
use specify\result\ExamplePackageResult;
use specify\event\ExamplePackageStart;
use specify\event\ExampleFinish;
use specify\event\ExamplePackageFinish;
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
                    new ExampleFinish(ExampleResult::pending('foo->bar()')),
                    new ExampleFinish(ExampleResult::passed('foo->bar1()')),
                    new ExampleFinish(ExampleResult::failed('foo->bar2()')),
                    new ExampleFinish(ExampleResult::pending('bar->bar()'))
                );
            });
            it('repoter example progress', function() {
                $result = "\e[0;36mP\e[0m.\e[0;31mF\e[0m\e[0;36mP\e[0m";

                expect(() ==> {
                    foreach ($this->events as $event) {
                        $this->repoter->handle($event);
                    }
                })->toPrint($result);
            });
        });
        context('when handle example package finish event', function() {
            beforeEach(function() {
                $processingTime = new ProcessingTime(1000.0, 2000.0);
                $group = new ExampleGroupResult('foo', Vector {
                    ExampleResult::passed('foo->bar1()')
                });

                $packageResult = new ExamplePackageResult('package', ImmVector {
                    $group
                }, $processingTime);

                $this->event = new ExamplePackageFinish($packageResult);
            });
            it('repoter example processing time', function() {
                expect(() ==> {
                    $this->repoter->handle($this->event);
                })->toPrint("\n\nFinished in 1000.000000 seconds\n");
            });
        });
    });
});
