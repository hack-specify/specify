<?hh //strict

namespace minitest\event;

trait NamedEvent
{

    private string $name;

    public function getName() : string
    {
        return $this->name;
    }

}
