<?hh //strict

namespace hhspecify\example;

final class Stack<T>
{

    public function __construct(
        private Vector<T> $items = Vector {}
    )
    {
    }

    public function add(T $value) : void
    {
        $this->items->add($value);
    }

    public function remove(T $value) : void
    {
        $indexAt = $this->items->linearSearch($value);
        $this->items->removeKey($indexAt);
    }

    public function count() : int
    {
        return $this->items->count();
    }

    public function isEmpty() : bool
    {
        return $this->items->isEmpty();
    }

}
