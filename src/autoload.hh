<?hh //strict

namespace minitest
{
    use minitest\result\ObjectBehaviorResult;
    use minitest\result\MethodBehaviorResult;
    use \ReflectionMethod;
    use \Generator;

    type ObjectBehaviorSpecification = Specification<ObjectBehaviorResult>;

    type SpecificationCollection = ImmVector<ObjectBehaviorSpecification>;
    type LifeCycleMessageSubscriberCollection = ImmVector<LifeCycleMessageSubscriber>;
    type BehaviorMethodCollection = Generator<int, BehaviorMethod, void>;

    type VerifyResultCollection = Vector<VerifyResult>;

    type MethodBehaviorResultCollection = Vector<MethodBehaviorResult>;
}

namespace minitest\result
{
    use minitest\result\MethodBehaviorResult;

    type MethodBehaviorResultCollection = Vector<MethodBehaviorResult>;
}
