<?hh //strict

namespace hhspecify\example;

use hhspecify\Specification;
use hhspecify\feature\FeatureVerifierBuilder as Feature;
use \Exception;


final class CarRegistrySpec implements Specification
{

    private Car $car;

    public function __construct(
        private CarRegistry $carRegistry = new CarRegistry()
    )
    {
        $this->car = new Car('Ferrari');
    }

    <<Feature("CarRegistry::register")>>
    public function register_a_car(Feature $feature) : void
    {
        $feature->setup(() ==> {
            $this->carRegistry = new CarRegistry();
        });

        $feature->when(() ==> {
            $this->carRegistry->register(new Car('Ferrari'));
        });

        $feature->then(() ==> {
            invariant($this->carRegistry->count() === 1, 'must have been registered car');
        });
    }

    <<Feature("CarRegistry::register")>>
    public function throw_an_exception_when_that_has_already_been_registered(Feature $feature) : void
    {
        $feature->setup(() ==> {
            $this->car = new Car('Ferrari');

            $this->carRegistry = new CarRegistry();
            $this->carRegistry->register($this->car);
        });

        $feature->when(() ==> {
            $this->carRegistry->register($this->car);
        });

        $feature->thenThrown((?Exception $exception) ==> {
            invariant($exception instanceof AlreadyRegisteredException, 'must throw an exception');
        });
    }

}
