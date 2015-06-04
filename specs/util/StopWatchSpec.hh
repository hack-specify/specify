<?hh //partial

use specify\util\StopWatch;

describe(StopWatch::class, function() {
    describe('->stop()', function() {
        beforeEach(function() {
            $this->stopWatch = new StopWatch();
            $this->stopWatch->start();
        });
        it('returns processing result', function() {
            $result = $this->stopWatch->stop();
            expect($result->getProcessingTime())->toBeGreaterThan(0);
        });
    });
});
