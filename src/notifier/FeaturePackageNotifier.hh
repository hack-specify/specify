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

use hhspecify\result\FeaturePackageResult;

interface FeaturePackageNotifier extends FeatureGroupNotifier
{
    public function featurePackageStart(string $description) : void;
    public function featurePackageFinish(FeaturePackageResult $result) : void;
}
