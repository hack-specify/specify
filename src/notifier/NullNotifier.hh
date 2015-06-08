<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\notifier;

use specify\LifeCycleNotifier;
use specify\result\FeatureResult;
use specify\result\FeatureGroupResult;
use specify\result\FeaturePackageResult;


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

    public function featureStart(string $description) : void
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
