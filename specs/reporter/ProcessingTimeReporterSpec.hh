<?hh //partial

use specify\event\FeaturePackageFinish;
use specify\result\FeaturePackageResult;
use specify\io\BufferWriter;
use specify\io\ConsoleOutput;
use specify\util\ProcessingTime;
use specify\reporter\ProcessingTimeReporter;


describe(ProcessingTimeReporter::class, function() {
    describe('->handle()', function() {
        beforeEach(function() {
            $this->bufferWriter = new BufferWriter();
            $this->consoleOutput = new ConsoleOutput($this->bufferWriter);
            $this->repoter = new ProcessingTimeReporter($this->consoleOutput);
        });
        it('report processing time', function() {
            $processingTime = new ProcessingTime(1000.0, 2000.0);
            $result = new FeaturePackageResult('package', Vector {}, $processingTime);
            $event = new FeaturePackageFinish($result);

            expect(() ==> {
                $this->repoter->receive($event);
            })->toPrint("Finished in 1000.000000 seconds\n");
        });
    });
});
