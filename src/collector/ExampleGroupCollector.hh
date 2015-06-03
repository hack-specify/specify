<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\collector;

use specify\Collector;
use specify\Specification;
use specify\example\ExampleGroup;
use specify\specification\PackageSpecification;
use specify\specification\NotSpecificationFileException;


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
            try {
                $reflection = $target->resolve($specificationFile);
            } catch (NotSpecificationFileException $exception) {
                continue;
            }

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
