<?hh //strict

namespace specify\specification;

use specify\Collector;
use \RecursiveDirectoryIterator;
use \FilesystemIterator;
use \RecursiveIteratorIterator;


class ObjectSpecificationCollector implements Collector<PackageSpecification, int, ObjectBehaviorSpecification>
{

    /**
     *
     */
    public function collectFrom(PackageSpecification $target) : ObjectBehaviorSpecificationCollection
    {
        $targetDirectory = $target->getPackageDirectory();
        $specificationFiles = $this->createIterator($targetDirectory);

        foreach ($specificationFiles as $specificationFile) {
            $fileName = $specificationFile->getPathname();

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
