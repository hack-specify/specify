<?hh //strict

namespace specify\collector;

use specify\Collector;
use \RecursiveDirectoryIterator;
use \FilesystemIterator;
use \RecursiveIteratorIterator;


class ExampleGroupCollector implements Collector<PackageSpecification, int, object>
{

    /**
     *
     */
    public function collectFrom(PackageSpecification $target) : ObjectBehaviorSpecificationCollection
    {
        $targetDirectory = $target->getPackageDirectory();
        $exampleGroupFiles = $this->createIterator($targetDirectory);

        foreach ($exampleGroupFiles as $exampleGroupFile) {
            $fileName = $exampleGroupFile->getPathname();

            $reflection = $target->resolve($fileName);
            yield $reflection->newInstance();
        }
    }

    /**
     * @param string $directory
     *
     * @return RecursiveIteratorIterator
     */
    private function createIterator(DirectoryPath $directory)
    {
        $directoryIterator = new RecursiveDirectoryIterator($directory,
            FilesystemIterator::CURRENT_AS_FILEINFO |
            FilesystemIterator::KEY_AS_PATHNAME |
            FilesystemIterator::SKIP_DOTS
        );

        $filterIterator = new RecursiveIteratorIterator($directoryIterator,
            RecursiveIteratorIterator::LEAVES_ONLY);

        return $filterIterator;
    }

}
