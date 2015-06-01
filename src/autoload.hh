<?hh //strict

namespace specify
{
    use specify\example\Example;
    use specify\result\ExampleResult;
    use specify\result\ExampleGroupResult;
    use specify\specification\PackageSpecification;

    use \ReflectionMethod;
    use \Generator;

    type LifeCycleMessageSubscriberCollection = ImmVector<LifeCycleMessageSubscriber>;

    type ExampleCollection = Generator<int, Example, void>;
    type VerifyResultCollection = Vector<VerifyResult>;
    type ExampleResultCollection = Vector<ExampleResult>;

    type ExampleReporter = LifeCycleMessageSubscriber;
    type ConfigOptions = shape(
        'package' => PackageSpecification,
        'exampleReporter' => ExampleReporter
    );
}

namespace specify\config
{
    use specify\LifeCycleMessageSubscriber;

    type PackageNamespace = string;
    type DirectoryPath = string;
    type Package = Pair<PackageNamespace, DirectoryPath>;
    type ExampleReporter = LifeCycleMessageSubscriber;
}

namespace specify\result
{
    use specify\result\ExampleResult;

    type ExampleResultCollection = Vector<ExampleResult>;
    type ExampleGroupResultCollection = Vector<ExampleGroupResult>;
}


namespace specify\collector
{
    use \Generator;
    use specify\example\Example;
    use specify\example\ExampleGroup;

    type DirectoryPath = string;
    type ExampleCollection = Generator<int, Example, void>;
    type ExampleGroupCollection = Generator<int, ExampleGroup, void>;
}

namespace specify\example
{
    use \Generator;

    type ExampleGroupCollection = ImmVector<ExampleGroup>;
    type ExampleCollection = Generator<int, Example, void>;
}

namespace specify\specification
{
    type PackageNamespace = string;
    type DirectoryPath = string;
    type SpecificationFile = string;

    /**
     * <code>
     * $package = Pair {'example\\spec\\', __DIR__};
     * </code>
     */
    type SpecificationPackage = Pair<PackageNamespace, DirectoryPath>;
}
