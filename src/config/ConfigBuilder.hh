<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\config;

use specify\Config;
use specify\Builder;
use specify\LifeCycleMessageSubscriber;
use specify\specification\PackageSpecification;
use specify\reporter\SpecificationReporter;


class ConfigBuilder implements Builder<Config>
{

    private ?PackageSpecification $package;
    private FeatureReporter $featureReporter;

    public function __construct()
    {
        $this->featureReporter = new SpecificationReporter();
    }

    public function package(SpecificationPackage $package) : this
    {
        $this->package = new PackageSpecification($package);
        return $this;
    }

    public function featureReporter(FeatureReporter $featureReporter) : this
    {
        $this->featureReporter = $featureReporter;
        return $this;
    }

    public function build() : Config
    {
        if ($this->package === null) {
            throw new RequiredException('The package is required');
        }

        return new Config(shape(
            'package' => $this->package,
            'featureReporter' => $this->featureReporter
        ));
    }

}
