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

enum LifeCycleEventType : string
{
    ExamplePackageStart = 'examplePackageStart';
    ExampleGroupStart = 'exampleGroupStart';
    ExampleStart = 'exampleStart';
    ExampleFinish = 'exampleFinish';
    ExampleGroupFinish = 'exampleGroupFinish';
    ExamplePackageFinish = 'examplePackageFinish';
}
