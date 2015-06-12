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
use \DateTime;


final class FeaturePackageStart extends AbstractNamedEvent implements LifeCycleEvent
{

    public function __construct(
        private string $description
    )
    {
        parent::__construct(LifeCycleEventType::ExamplePackageStart);
    }

    public function getDescription() : string
    {
        return $this->description;
    }

}
