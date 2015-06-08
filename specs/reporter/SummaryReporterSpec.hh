<?hh //partial

use specify\event\FeaturePackageFinish;
use specify\result\FeatureResult;
use specify\result\FeatureGroupResult;
use specify\result\FeaturePackageResult;
use specify\io\BufferWriter;
use specify\io\ConsoleOutput;
use specify\util\ProcessingTime;
use specify\reporter\SummaryReporter;


describe(SummaryReporter::class, function() {
    describe('->handle()', function() {
        beforeEach(function() {
            $this->bufferWriter = new BufferWriter();
            $this->consoleOutput = new ConsoleOutput($this->bufferWriter);
            $this->reporter = new SummaryReporter($this->consoleOutput);

            $this->processingTime = new ProcessingTime(1000.0, 2000.0);
        });
        context('when handle example package finish event', function() {
            context('when passed', function() {
                beforeEach(function() {
                    $group = new FeatureGroupResult('foo', Vector {
                        FeatureResult::passed('foo->bar1()')
                    });

                    $packageResult = new FeaturePackageResult('package', ImmVector {
                        $group
                    }, $this->processingTime);

                    $this->event = new FeaturePackageFinish($packageResult);
                });
                it('report verify summary by passed color', function() {
                    expect(() ==> {
                        $this->reporter->receive($this->event);
                    })->toPrint("\e[0;32m1 feature, 0 failures, 0 pending\e[0m\n");
                });
            });
            context('when failed', function() {
                beforeEach(function() {
                    $group = new FeatureGroupResult('foo', Vector {
                        FeatureResult::failed('foo->bar1()')
                    });

                    $packageResult = new FeaturePackageResult('package', ImmVector {
                        $group
                    }, $this->processingTime);

                    $this->event = new FeaturePackageFinish($packageResult);
                });
                it('report verify summary by failed color', function() {
                    expect(() ==> {
                        $this->reporter->receive($this->event);
                    })->toPrint("\e[0;31m1 feature, 1 failures, 0 pending\e[0m\n");
                });
            });
        });
    });
});
