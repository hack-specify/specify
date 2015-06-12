<?hh //strict

/**
 * This file is part of hhspecify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhspecify\feature;

final class FeatureDescription
{

    public function __construct(
        private string $label = 'none',
        private string $description = 'feature description empty'
    )
    {
    }

    public function getLabel() : string
    {
        return $this->label;
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function __toString() : string
    {
        return sprintf('%s - %s',
            $this->getLabel(),
            $this->getDescription()
        );
    }

}
