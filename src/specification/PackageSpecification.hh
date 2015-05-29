<?hh //strict

namespace specify\specification;

use \ReflectionClass;


class PackageSpecification
{

    private PackageNamespace $ns;
    private DirectoryPath $packageDirectory;

    public function __construct(
        SpecificationPackage $package)
    {
        $this->ns = $package->at(0);
        $this->packageDirectory = realpath($package->at(1));
    }

    public function resolve(SpecificationFile $file) : ReflectionClass
    {
        $relativeClass = $this->relativeClassFrom($file);
        $fullName = $this->ns . $relativeClass;

        return new ReflectionClass($fullName);
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
