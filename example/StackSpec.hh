<?hh //strict

namespace specify\example;

use \Exception;
use specify\Specification;
use specify\feature\FeatureVerifierBuilder as Feature;


final class StackSpec implements Specification
{

    public function __construct(
        private Stack<int> $stack = new Stack()
    )
    {
    }

    <<Feature("Stack::add")>>
    public function add_value_to_stack(Feature $feature) : void
    {
        $feature->setup(() ==> {
            $this->stack = new Stack();
        });

        $feature->when(() ==> {
            $this->stack->add(1);
        });

        $feature->then(() ==> {
            invariant($this->stack->count() === 1, 'must have been added value');
        });
    }

    <<Feature("Stack::remove")>>
    public function remove_value_from_stack(Feature $feature) : void
    {
        $feature->setup(() ==> {
            $this->stack = new Stack();
            $this->stack->add(1);
        });

        $feature->when(() ==> {
            $this->stack->remove(1);
        });

        $feature->then(() ==> {
            invariant($this->stack->isEmpty(), 'must be empty');
        });
    }

}
