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

use specify\LifeCycleEvent;
use specify\LifeCycleNotifier;
use specify\event\FeaturePackageStart;
use specify\event\FeatureGroupStart;
use specify\event\FeatureStart;
use specify\event\FeatureFinish;
use specify\event\FeatureGroupFinish;
use specify\event\FeaturePackageFinish;
use specify\result\FeatureResult;
use specify\result\FeatureGroupResult;
use specify\result\FeaturePackageResult;
use specify\feature\FeatureDescription;


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
