<?hh //partial

use specify\example\ExampleGroup;
use specify\fixtures\A;
use \ReflectionClass;
use \Exception;


describe(ExampleGroup::class, function() {
    describe('->getDescription()', function() {
        beforeEach(function() {
            $this->exampleGroup = new ExampleGroup(new ReflectionClass(A::class));
        });
        it('returns description of example group', function() {
            expect($this->exampleGroup->getDescription())->toBe("specify\\fixtures\\A");
        });
    });
});
