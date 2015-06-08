<?hh //strict

namespace specify\example;

use specify\Specification;
use specify\feature\FeatureVerifierBuilder as Feature;
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

    <<Feature("registration of car")>>
    public function register_a_new_car(Feature $feature) : void
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

    <<Feature("registration of car")>>
    public function tries_to_already_registered_the_registered_car(Feature $feature) : void
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
            invariant($exception instanceof Exception, 'must throw an exception');
        });
    }

}
