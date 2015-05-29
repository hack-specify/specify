<?hh //strict

namespace minitest\event;

use DateTimeImmutable;

trait NamedEvent
{

    private string $name;
    private DateTimeImmutable $sendAt;

    public function getName() : string
    {
        return $this->name;
    }

    public function getSendAt() : DateTimeImmutable
    {
        return $this->sendAt;
    }

}
