<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\cli;

use hhspecify\Config;

class Argument
{

    private ImmMap<string, mixed> $options;

    public function __construct(
        private ?Traversable<string> $argv = []
    )
    {
        $options = getopt('c::h::', ['config::', 'help::']);
        $this->options = new ImmMap($options);
    }

    public function getConfigFile() : string
    {
        $value = $this->getOption('c', 'config');

        if ($value === null) {
            return Config::FILE_NAME;
        }

        return (string) $value;
    }

    public function hasHelpOption() : bool
    {
        $value = $this->getOption('h', 'help');

        if ($value === null) {
            return false;
        }

        return true;
    }

    /**
     * Get the option value for CLI
     *
     * <code>
     * $value = $this->getOption('c', 'config'); //short name, long name
     * </code>
     */
    private function getOption(...) : mixed
    {
        $value = null;
        $optionNames = func_get_args();

        foreach ($optionNames as $optionName) {
            $value = $this->options->get($optionName);
            if ($value === null) {
                continue;
            }
            break;
        }

        return $value;
    }

}
