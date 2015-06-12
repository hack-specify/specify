<?hh //strict

namespace hhspecify\example;

interface Registry<T>
{
    public function register(T $value) : void;
    public function unregister(T $value) : void;
}
