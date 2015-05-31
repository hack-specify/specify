<?hh //strict

namespace specify
{
    use specify\result\ObjectBehaviorResult;
    use specify\result\ExampleResult;
    use \ReflectionMethod;
    use \Generator;

    type ObjectBehaviorSpecification = Specification<ObjectBehaviorResult>;

    type SpecificationCollection = ImmVector<ObjectBehaviorSpecification>;
    type LifeCycleMessageSubscriberCollection = ImmVector<LifeCycleMessageSubscriber>;
    type BehaviorMethodCollection = Generator<int, BehaviorMethod, void>;

    type VerifyResultCollection = Vector<VerifyResult>;

    type ExampleResultCollection = Vector<ExampleResult>;
}

namespace specify\result
{
    use specify\result\ExampleResult;

    type ExampleResultCollection = Vector<ExampleResult>;
}


namespace specify\runner
{
    use \Generator;
    use specify\BehaviorMethod;

    type ExampleGroupRunnerCollection = ImmVector<ExampleGroupRunner>;
    type BehaviorMethodCollection = Generator<int, BehaviorMethod, void>;
}

namespace specify\specification
{
    use specify\Specification;
    use specify\result\ObjectBehaviorResult;
    use \Generator;

    type PackageNamespace = string;
    type DirectoryPath = string;
    type SpecificationFile = string;

    /**
     * <code>
     * $package = Pair {'example\\spec\\', __DIR__};
     * </code>
     */
    type SpecificationPackage = Pair<PackageNamespace, DirectoryPath>;
    type ObjectBehaviorSpecification = Specification<ObjectBehaviorResult>;

    type ObjectBehaviorSpecificationCollection = Generator<int, ObjectBehaviorSpecification, void>;
}
