<?hh //strict

namespace hhspecify\example;

final class Car
{

    public function __construct(
        private string $name
    )
    {
    }

    public function getName() : string
    {
        return $this->name;
    }

    public function registerTo(Registry<Car> $registry) : void
    {
        $registry->register($this);
    }

}
