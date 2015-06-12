<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify;

use hhspecify\specification\PackageSpecification;


class Config
{

    const string FILE_NAME = 'hhspecify.hh';

    private PackageSpecification $package;
    private FeatureReporter $featureReporter;

    public function __construct(ConfigOptions $config)
    {
        $this->package = $config['package'];
        $this->featureReporter = $config['featureReporter'];
    }

    public function getPackage() : PackageSpecification
    {
        return $this->package;
    }

    public function getFeatureReporter() : FeatureReporter
    {
        return $this->featureReporter;
    }

}
