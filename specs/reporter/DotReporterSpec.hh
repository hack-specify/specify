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
        context('when handle example package finish event', function() {
            beforeEach(function() {
                $processingTime = new ProcessingTime(1000.0, 2000.0);
                $group = new FeatureGroupResult('foo', Vector {
                    FeatureResult::passed('foo->bar1()')
                });

                $packageResult = new FeaturePackageResult('package', ImmVector {
                    $group
                }, $processingTime);

                $this->event = new FeaturePackageFinish($packageResult);
            });
            it('repoter example processing time', function() {

                $results = [];
                $results[] = "\n\nFinished in 1000.000000 seconds\n";
                $results[] = "\e[0;32m1 feature, 0 failures, 0 pending\e[0m\n\n";

                $output = implode($results, '');

                expect(() ==> {
                    $this->repoter->receive($this->event);
                })->toPrint($output);
            });
        });
    });
});
