<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\feature;

final class FeatureDescription
{

    public function __construct(
        private string $description = 'feature description empty',
        private string $detailDescription = ''
    )
    {
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function getDetailDescription() : string
    {
        return $this->detailDescription;
    }

    public function __toString() : string
    {
        return sprintf('%s - %s',
            $this->getDescription(),
            $this->getDetailDescription()
        );
    }

}
