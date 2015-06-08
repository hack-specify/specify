<?hh //strict

namespace specify\example;

final class CarRegistry implements Registry<Car>
{

    public function __construct(
        private Map<string, Car> $cars = Map {}
    )
    {
    }

    public function register(Car $car) : void
    {
        if ($this->cars->containsKey($car->getName())) {
            throw new AlreadyRegisteredException();
        }

        $this->cars->set($car->getName(), $car);
    }

    public function unregister(Car $car) : void
    {
        $this->cars->remove($car->getName());
    }

    public function count() : int
    {
        return $this->cars->count();
    }

}
