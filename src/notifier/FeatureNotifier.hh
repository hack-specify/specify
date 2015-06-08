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

use specify\result\FeatureResult;
use specify\feature\FeatureDescription;

interface FeatureNotifier
{
    public function featureStart(FeatureDescription $description) : void;
    public function featureFinish(FeatureResult $result) : void;
}
