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

use hhspecify\result\FeatureResult;
use hhspecify\feature\FeatureDescription;

interface FeatureNotifier
{
    public function featureStart(FeatureDescription $description) : void;
    public function featureFinish(FeatureResult $result) : void;
}
