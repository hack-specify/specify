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

use specify\result\FeatureGroupResult;

interface ExampleGroupNotifier
{
    public function exampleGroupStart(string $description) : void;
    public function exampleGroupFinish(FeatureGroupResult $result) : void;
}
