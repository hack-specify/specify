<?hh //strict

namespace specify
{
    use specify\result\ObjectBehaviorResult;
    use specify\result\MethodBehaviorResult;
    use \ReflectionMethod;
    use \Generator;

    type ObjectBehaviorSpecification = Specification<ObjectBehaviorResult>;

    type SpecificationCollection = ImmVector<ObjectBehaviorSpecification>;
    type LifeCycleMessageSubscriberCollection = ImmVector<LifeCycleMessageSubscriber>;
    type BehaviorMethodCollection = Generator<int, BehaviorMethod, void>;

    type VerifyResultCollection = Vector<VerifyResult>;

    type MethodBehaviorResultCollection = Vector<MethodBehaviorResult>;
}

namespace specify\result
{
    use specify\result\MethodBehaviorResult;

    type MethodBehaviorResultCollection = Vector<MethodBehaviorResult>;
}
