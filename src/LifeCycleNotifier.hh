<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify;

use specify\result\FeatureGroupResult;
use specify\result\FeaturePackageResult;
use specify\notifier\FeatureNotifier;
use specify\notifier\FeatureGroupNotifier;
use specify\notifier\FeaturePackageNotifier;

interface LifeCycleNotifier extends FeatureNotifier, FeaturePackageNotifier, FeatureGroupNotifier
{
}
