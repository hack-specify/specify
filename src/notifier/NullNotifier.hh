<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\notifier;

use hhspecify\LifeCycleNotifier;
use hhspecify\result\FeatureResult;
use hhspecify\result\FeatureGroupResult;
use hhspecify\result\FeaturePackageResult;
use hhspecify\feature\FeatureDescription;


class NullNotifier implements LifeCycleNotifier
{

    public function __construct(
        private LifeCycleMessageSubscriberCollection $subscribers
    )
    {
    }

    public function featurePackageStart(string $description) : void
    {
    }

    public function featureGroupStart(string $description) : void
    {
    }

    public function featureStart(FeatureDescription $description) : void
    {
    }

    public function featureFinish(FeatureResult $result) : void
    {
    }

    public function featureGroupFinish(FeatureGroupResult $result) : void
    {
    }

    public function featurePackageFinish(FeaturePackageResult $result) : void
    {
    }

}
