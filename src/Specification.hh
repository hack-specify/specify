<?hh //strict

namespace specify;

interface Specification<Tr>
{
    public function verify() : Tr;
}
