<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\collector;

use hhspecify\Collector;
use hhspecify\Specification;
use hhspecify\feature\FeatureGroup;
use hhspecify\specification\PackageSpecification;
use hhspecify\specification\NotSpecificationFileException;


class FeatureGroupCollector implements Collector<PackageSpecification, FeatureGroupCollection>
{

    /**
     *
     */
    public function collectFrom(PackageSpecification $target) : FeatureGroupCollection
    {
        $groups = Vector {};
        $targetDirectory = $target->getPackageDirectory();
        $specificationFiles = $this->getSpecificationFiles($targetDirectory);

        foreach ($specificationFiles as $specificationFile) {
            try {
                $specification = $target->resolve($specificationFile);
            } catch (NotSpecificationFileException $exception) {
                continue;
            }

            $group = new FeatureGroup($specification);
            $groups->add($group);
        }
        $groups->shuffle();

        return $groups->toImmVector();
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
