<?hh //strict

/**
 * This file is part of specify.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace specify\specification;

use specify\Specification;
use \ReflectionClass;
use \ReflectionException;


class PackageSpecification
{

    private PackageNamespace $ns;
    private DirectoryPath $packageDirectory;

    public function __construct(
        SpecificationPackage $package)
    {
        $this->ns = (string) $package['namespace'];
        $this->packageDirectory = realpath($package['packageDirectory']);
    }

    <<__Memoize>>
    public function getNamespace() : PackageNamespace
    {
        $atoms = explode('\\', $this->ns);
        $atoms = (new Vector($atoms))->filter((string $atom) ==> {
            return trim($atom) !== '';
        });

        return implode('\\', $atoms);
    }

    public function getPackageDirectory() : DirectoryPath
    {
        return $this->packageDirectory;
    }

    public function resolve(SpecificationFile $file) : Specification
    {
        $relativeClass = $this->relativeClassFrom($file);
        $fullName = $this->ns . $relativeClass;

        try {
            $reflection = new ReflectionClass($fullName);
        } catch (ReflectionException $exception) {
            throw new NotSpecificationFileException();
        }

        if ($reflection->implementsInterface(Specification::class) === false) {
            throw new NotSpecificationFileException();
        }

        return $reflection->newInstance();
    }

    private function relativeClassFrom(SpecificationFile $file) : string
    {
        $replaceTargets = [
            $this->packageDirectory . '/',
            '/',
            '.hh'
        ];
        $replaceValues = [
            '',
            '\\',
            ''
        ];

        $relativeClass = str_replace($replaceTargets, $replaceValues, $file);

        return $relativeClass;
    }

}
