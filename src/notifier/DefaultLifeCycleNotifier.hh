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

use hhspecify\LifeCycleEvent;
use hhspecify\LifeCycleNotifier;
use hhspecify\event\FeaturePackageStart;
use hhspecify\event\FeatureGroupStart;
use hhspecify\event\FeatureStart;
use hhspecify\event\FeatureFinish;
use hhspecify\event\FeatureGroupFinish;
use hhspecify\event\FeaturePackageFinish;
use hhspecify\result\FeatureResult;
use hhspecify\result\FeatureGroupResult;
use hhspecify\result\FeaturePackageResult;
use hhspecify\feature\FeatureDescription;


class DefaultLifeCycleNotifier implements LifeCycleNotifier
{

    public function __construct(
        private LifeCycleMessageSubscriberCollection $subscribers
    )
    {
    }

    public function featurePackageStart(string $description) : void
    {
        $this->send(new FeaturePackageStart($description));
    }

    public function featureGroupStart(string $description) : void
    {
        $this->send(new FeatureGroupStart($description));
    }

    public function featureStart(FeatureDescription $description) : void
    {
        $this->send(new FeatureStart($description));
    }

    public function featureFinish(FeatureResult $result) : void
    {
        $this->send(new FeatureFinish($result));
    }

    public function featureGroupFinish(FeatureGroupResult $result) : void
    {
        $this->send(new FeatureGroupFinish($result));
    }

    public function featurePackageFinish(FeaturePackageResult $result) : void
    {
        $this->send(new FeaturePackageFinish($result));
    }

    private function send(LifeCycleEvent $event) : void
    {
        foreach ($this->subscribers as $subscriber) {
            $event->sendTo($subscriber);
        }
    }

}
