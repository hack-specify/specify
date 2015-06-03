<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\io;


class ConsoleOutput implements Console
{

    private Writer $writer;

    public function __construct(
        ?Writer $writer = null
    )
    {
        $outputWriter = new StdoutWriter();

        if ($writer !== null) {
            $outputWriter = $writer;
        }
        $this->writer = $outputWriter;
    }

    /**
     * Write to standard output
     *
     * <code>
     * $output = new ConsoleOutput();
     * $output->write('<green>%d example, %d failures</green>', 10, 0);
     * </code>
     */
    public function write(string $format, ...) : void
    {
        $values = array_slice(func_get_args(), 1);
        $content = $this->format($format, $values);

        $this->writer->write($content);
    }

    /**
     * Write to standard output with a line break
     *
     * <code>
     * $output = new ConsoleOutput();
     * $output->write('<green>%d example, %d failures</green>', 10, 0);
     * </code>
     */
    public function writeln(string $format, ...) : void
    {
        $values = array_slice(func_get_args(), 1);
        $content = $this->format($format, $values);

        $this->writer->writeln($content);
    }

    private function format(string $format, array<mixed> $values) : string
    {
        $arugments = $values;
        $coloredFormat = $this->resolveColor($format);

        array_unshift($arugments, $coloredFormat);
        $value = call_user_func_array('sprintf', $arugments);

        return $value;
    }

    private function resolveColor(string $format) : string
    {
        $content = $format;
        $colors = ForegroundColor::getValues();

        foreach ($colors as $key => $color) {
            $colorName = lcfirst($key);
            $regexp = "/<{$colorName}>(.+?)<\/{$colorName}>/";
            $content = preg_replace($regexp, "\e[" . (string) $color . "m$1\e[0m", $content); //nullable!!
        }

        return $content;
    }

}
