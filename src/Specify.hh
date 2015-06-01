<?hh //strict

namespace specify;

use specify\config\ConfigBuilder;


class Specify
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
