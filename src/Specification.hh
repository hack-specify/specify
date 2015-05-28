<?hh //strict

namespace minitest;

interface Specification<Tr>
{
    public function verify() : Tr;
}
