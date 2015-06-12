<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify;

use hhspecify\result\FeatureGroupResult;
use hhspecify\result\FeaturePackageResult;
use hhspecify\notifier\FeatureNotifier;
use hhspecify\notifier\FeatureGroupNotifier;
use hhspecify\notifier\FeaturePackageNotifier;

interface LifeCycleNotifier extends FeatureNotifier, FeaturePackageNotifier, FeatureGroupNotifier
{
}
