<?hh //strict

namespace specify\collector;

use specify\Collector;
use specify\Specification;
use specify\example\ExampleGroup;
use specify\specification\PackageSpecification;


class ExampleGroupCollector implements Collector<PackageSpecification, int, ExampleGroup>
{

    /**
     *
     */
    public function collectFrom(PackageSpecification $target) : ExampleGroupCollection
    {
        $targetDirectory = $target->getPackageDirectory();
        $specificationFiles = $this->getSpecificationFiles($targetDirectory);

        foreach ($specificationFiles as $specificationFile) {
            $reflection = $target->resolve($specificationFile);
            yield new ExampleGroup($reflection);
        }
    }

    /**
     * @param string $directory
     */
    private function getSpecificationFiles(DirectoryPath $directory) : SpecificationFileCollection
    {
        $collector = new SpecificationFileCollector();
        return $collector->collectFrom($directory);
    }

}
