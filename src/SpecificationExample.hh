<?hh //strict

namespace specify;

interface SpecificationExample<Tr>
{
    public function verify(LifeCycleNotifier $notifier) : Tr;
}
