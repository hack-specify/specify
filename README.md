specify
============================

[![Build Status](https://travis-ci.org/hack-specify/specify.svg?branch=master)](https://travis-ci.org/hack-specify/specify)

Installation
----------------------------

Installed by [composer](https://getcomposer.org/).

	composer require specify/specify

Basic usage
----------------------------

### Create a configuration file

Create a configuration file in order to verify the specifications.  
Use the **configure** method to do the setup.  

```hack
<?hh //partial

use specify\Specify;
use specify\config\ConfigBuilder;
use specify\reporter\SpecificationReporter;

Specify::configure((ConfigBuilder $builder) ==> {

    $package = Pair {
        'vendorname\\spec\\', //The package namespace of the spec
        __DIR__ . '/spec' //The directory of the package spec
    };

    $builder->package($package)
        ->exampleReporter(new SpecificationReporter());

});
```

### Create a specification file

It will create a specification file to **vendorname/spec**.  
Specification must implement **specify\Specification**.  

It will specify the specification in the **Example** attribute.  

```hack
<?hh //strict

namespace vendorname\spec;

use specify\Specification;

class StackSpecification implements Specification
{

    private Stack<int> $stack;

    public function __construct()
    {
        $this->stack = new Stack();
    }

    <<Example("->push() - returns the size")>>
    public function push() : int
    {
        $result = $this->stack->push(100);
        invariant($result === 1, "must returns the size");
    }

}
```

### Verify the specification

In the package root directory run the following command.  

	vendor/bin/specify


Run the test
----------------------------

	composer install
	composer test
