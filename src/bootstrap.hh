<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify
{
    use hhspecify\specification\PackageSpecification;

    type FeatureReporter = LifeCycleMessageSubscriber;
    type ConfigOptions = shape(
        'package' => PackageSpecification,
        'featureReporter' => FeatureReporter
    );
}

namespace hhspecify\config
{
    use hhspecify\LifeCycleMessageSubscriber;

    type PackageNamespace = string;
    type DirectoryPath = string;

    type SpecificationPackage = shape(
        'namespace' => PackageNamespace,
        'packageDirectory' => DirectoryPath
    );
    type FeatureReporter = LifeCycleMessageSubscriber;
}

namespace hhspecify\result
{
    use hhspecify\result\FeatureResult;

    type FeatureResultCollection = ImmVector<FeatureResult>;
    type FeatureGroupResultCollection = ImmVector<FeatureGroupResult>;
    type LabelGroupFeatureResult = ImmMap<string, ImmVector<FeatureResult>>;
}


namespace hhspecify\collector
{
    use hhspecify\FeatureSpecification;
    use hhspecify\feature\FeatureGroup;
    use hhspecify\notifier\FeatureNotifier;
    use hhspecify\result\FeatureResult;

    type DirectoryPath = string;
    type SpecificationFile = string;
    type SpecificationFileCollection = ImmVector<SpecificationFile>;
    type FeatureCollection = ImmVector<FeatureSpecification<FeatureResult, FeatureNotifier>>;
    type FeatureGroupCollection = ImmVector<FeatureGroup>;
}

namespace hhspecify\feature
{
    use hhspecify\FeatureSpecification;
    use hhspecify\result\FeatureResult;
    use hhspecify\notifier\FeatureNotifier;

    type FeatureGroupCollection = ImmVector<FeatureGroup>;
    type FeatureCollection = ImmVector<FeatureSpecification<FeatureResult, FeatureNotifier>>;
}


namespace hhspecify\event
{
    use hhspecify\result\FeatureResult;

    type FeatureResultCollection = ImmVector<FeatureResult>;
}

namespace hhspecify\notifier
{
    use hhspecify\LifeCycleMessageSubscriber;

    type LifeCycleMessageSubscriberCollection = ImmVector<LifeCycleMessageSubscriber>;
}

namespace hhspecify\reporter
{
    use hhspecify\LifeCycleMessageSubscriber;

    type ReporterCollection = ImmVector<LifeCycleMessageSubscriber>;
}

namespace hhspecify\specification
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
