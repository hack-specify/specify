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

use hhspecify\config\ConfigBuilder;


class HHSpecify
{

    private static ?ConfigBuilder $builder;

    public static function configure((function(ConfigBuilder): void) $configurator) : void
    {
        self::$builder = new ConfigBuilder();
        $configurator(self::$builder);
    }

    public static function currentConfig() : Config
    {
        if (self::$builder === null) {
            self::$builder = new ConfigBuilder();
        }

        return self::$builder->build();
    }

}
