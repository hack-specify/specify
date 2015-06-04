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

use specify\result\ExampleGroupResult;
use specify\result\ExamplePackageResult;
use specify\notifier\ExampleNotifier;
use specify\notifier\ExampleGroupNotifier;
use specify\notifier\ExamplePackageNotifier;

interface LifeCycleNotifier extends ExampleNotifier, ExamplePackageNotifier, ExampleGroupNotifier
{
}
