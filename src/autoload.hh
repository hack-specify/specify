<?hh //strict

namespace specify
{
    use specify\example\MethodExample;
    use specify\result\ExampleResult;
    use specify\result\ExampleGroupResult;
    use \ReflectionMethod;
    use \Generator;

    type ObjectBehaviorSpecification = Specification<ExampleResult>;

    type SpecificationCollection = ImmVector<ObjectBehaviorSpecification>;
    type LifeCycleMessageSubscriberCollection = ImmVector<LifeCycleMessageSubscriber>;
    type MethodExampleCollection = Generator<int, MethodExample, void>;

    type VerifyResultCollection = Vector<VerifyResult>;

    type ExampleResultCollection = Vector<ExampleResult>;
}

namespace specify\result
{
    use specify\result\ExampleResult;

    type ExampleResultCollection = Vector<ExampleResult>;
}


namespace specify\collector
{
    use \Generator;
    use specify\example\MethodExample;

    type MethodExampleCollection = Generator<int, MethodExample, void>;
}

namespace specify\runner
{
    use \Generator;
    use specify\example\MethodExample;

    type ExampleGroupRunnerCollection = ImmVector<ExampleGroupRunner>;
    type MethodExampleCollection = Generator<int, MethodExample, void>;
}

namespace specify\specification
{
    use specify\Specification;
    use specify\result\ExampleResult;
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
    type ObjectBehaviorSpecification = Specification<ExampleResult>;

    type ObjectBehaviorSpecificationCollection = Generator<int, ObjectBehaviorSpecification, void>;
}
