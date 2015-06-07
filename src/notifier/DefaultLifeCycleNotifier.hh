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
use specify\event\ExamplePackageStart;
use specify\event\ExampleGroupStart;
use specify\event\ExampleStart;
use specify\event\ExampleFinish;
use specify\event\ExampleGroupFinish;
use specify\event\ExamplePackageFinish;
use specify\result\FeatureResult;
use specify\result\FeatureGroupResult;
use specify\result\FeaturePackageResult;


class DefaultLifeCycleNotifier implements LifeCycleNotifier
{

    public function __construct(
        private LifeCycleMessageSubscriberCollection $subscribers
    )
    {
    }

    public function examplePackageStart(string $description) : void
    {
        $this->send(new ExamplePackageStart($description));
    }

    public function exampleGroupStart(string $description) : void
    {
        $this->send(new ExampleGroupStart($description));
    }

    public function exampleStart(string $description) : void
    {
        $this->send(new ExampleStart($description));
    }

    public function exampleFinish(FeatureResult $result) : void
    {
        $this->send(new ExampleFinish($result));
    }

    public function exampleGroupFinish(FeatureGroupResult $result) : void
    {
        $this->send(new ExampleGroupFinish($result));
    }

    public function examplePackageFinish(FeaturePackageResult $result) : void
    {
        $this->send(new ExamplePackageFinish($result));
    }

    private function send(LifeCycleEvent $event) : void
    {
        foreach ($this->subscribers as $subscriber) {
            $event->sendTo($subscriber);
        }
    }

}
