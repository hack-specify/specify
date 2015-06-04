<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

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

    type SpecificationPackage = shape(
        'namespace' => PackageNamespace,
        'packageDirectory' => DirectoryPath
    );
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
    use specify\SpecificationExample;
    use specify\example\Example;
    use specify\example\ExampleGroup;
    use specify\result\ExampleResult;

    type DirectoryPath = string;
    type SpecificationFile = string;
    type SpecificationFileCollection = ImmVector<SpecificationFile>;
    type ExampleCollection = ImmVector<SpecificationExample<ExampleResult>>;
    type ExampleGroupCollection = ImmVector<ExampleGroup>;
}

namespace specify\example
{
    use \Generator;
    use specify\SpecificationExample;
    use specify\result\ExampleResult;

    type ExampleGroupCollection = ImmVector<ExampleGroup>;
    type ExampleCollection = ImmVector<SpecificationExample<ExampleResult>>;
}

namespace specify\reporter
{
    use specify\LifeCycleMessageSubscriber;

    type ReporterCollection = ImmVector<LifeCycleMessageSubscriber>;
}

namespace specify\specification
{
    type PackageNamespace = string;
    type DirectoryPath = string;
    type SpecificationFile = string;

    /**
     * <code>
     * $package = shape(
     *     'namespace' => 'vendorname\\spec\\',
     *     'packageDirectory' => '/path/to/'
     * );
     * </code>
     */
    type SpecificationPackage = shape(
        'namespace' => PackageNamespace,
        'packageDirectory' => DirectoryPath
    );
}
