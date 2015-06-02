<?hh //strict

namespace specify\collector;

use specify\Collector;

class SpecificationFileCollector implements Collector<DirectoryPath, int, SpecificationFile>
{

    public function collectFrom(DirectoryPath $target) : SpecificationFileCollection
    {
        $files = $this->findFiles($target);

        foreach ($files as $file) {
            if ($this->matchFile($file) === false) {
                continue;
            }
            yield $file;
        }
    }

    private function matchFile(string $entry) : bool
    {
        if (preg_match('/^.+\.hh$/', $entry) === 0) {
            return false;
        }
        return true;
    }

    private function matchDirectory(string $entry) : bool
    {
        if ($entry === ".." || $entry === ".") {
            return false;
        }
        return true;
    }

    private function findFiles(string $target) : SpecificationFileCollection
    {
        $targetDirectory = dir($target);
        $currentDirectory = $target;

        while (false !== ($entry = $targetDirectory->read())) {
            if ($this->matchDirectory($entry) === false) {
                continue;
            }

            $absoluteFilePath = $currentDirectory . '/' . $entry;

            if (is_file($absoluteFilePath)) {
                yield $absoluteFilePath;
            } else if (is_dir($absoluteFilePath)) {
                $files = $this->findFiles($absoluteFilePath);

                foreach ($files as $file) {
                    yield $file;
                }
            }
        }

        $targetDirectory->close();
    }

}
