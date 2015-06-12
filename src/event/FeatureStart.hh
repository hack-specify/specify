<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\event;

use hhspecify\LifeCycleEvent;
use hhspecify\LifeCycleEventType;
use hhspecify\feature\FeatureDescription;
use hhspecify\result\ExampleResult;


final class FeatureStart extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private FeatureDescription $description
    )
    {
        parent::__construct(LifeCycleEventType::ExampleStart);
    }

    public function getDescription() : FeatureDescription
    {
        return $this->description;
    }

}
