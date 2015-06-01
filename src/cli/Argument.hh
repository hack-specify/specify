<?hh //strict

namespace specify\cli;

use specify\Config;

class Argument
{

    private ImmMap<string, mixed> $options;

    public function __construct(
        private ?Traversable<string> $argv = []
    )
    {
        $options = getopt('c:', ['config::']);
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
