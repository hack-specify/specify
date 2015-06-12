<?hh //partial

use hhspecify\result\FeatureResult;
use hhspecify\result\FeatureGroupResult;
use hhspecify\result\FeaturePackageResult;
use hhspecify\event\FeaturePackageStart;
use hhspecify\event\FeatureFinish;
use hhspecify\event\FeaturePackageFinish;
use hhspecify\feature\FeatureDescription;
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
                $description1 = new FeatureDescription('', 'foo->bar()');
                $description2 = new FeatureDescription('', 'foo->bar1()');
                $description3 = new FeatureDescription('', 'foo->bar2()');
                $description4 = new FeatureDescription('', 'bar->bar()');

                $this->events = tuple(
                    new FeatureFinish(FeatureResult::pending($description1)),
                    new FeatureFinish(FeatureResult::passed($description2)),
                    new FeatureFinish(FeatureResult::failed($description3)),
                    new FeatureFinish(FeatureResult::pending($description4))
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
