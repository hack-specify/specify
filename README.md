HHSpecify
============================

[![Build Status](https://travis-ci.org/hhspecify/hhspecify.svg?branch=0.1.1-alpha4)](https://travis-ci.org/hhspecify/hhspecify)

**HHSpecify** is BDD testing framework for [Hack](http://hacklang.org/), inspired by [spock](https://github.com/spockframework/spock).


![Screen Shot](https://raw.githubusercontent.com/hack-specify/specify/master/screen-shot.png)

Installation
----------------------------

Installed by [composer](https://getcomposer.org/).

	composer require hhspecify/hhspecify

Basic usage
----------------------------

### Create a configuration file

Create a configuration file in order to verify the specifications.  
Use the **configure** method to do the setup.  

```hack
<?hh //partial

use hhspecify\HHSpecify;
use hhspecify\config\ConfigBuilder;
use hhspecify\reporter\SpecificationReporter;

HHSpecify::configure((ConfigBuilder $builder) ==> {

    $package = shape(
        'namespace' => 'vendorname\\spec\\', //The package namespace of the spec
        'packageDirectory' => __DIR__ . '/spec' //The directory of the package spec
    );

    $builder->package($package)
        ->featureReporter(new SpecificationReporter());

});
```

### Create a specification file

It will create a specification file to **vendorname/spec**.  
Specification must implement **hhspecify\Specification**.  

It will specify the specification in the **Feature** attribute.  

```hack
use hhspecify\Specification;
use hhspecify\feature\FeatureVerifierBuilder as Feature;

final class StackSpec implements Specification
{

    public function __construct(
        private Stack<int> $stack = new Stack()
    )
    {
    }

    <<Feature("Stack::add")>>
    public function add_value_to_stack(Feature $feature) : void
    {
    }
}
```

### Write a feature specification

It will describe the setup / when / then block.  
Block specified in lambda expression.

```hack
<<Feature("Stack::add")>>
public function add_value_to_stack(Feature $feature) : void
{
    //setup block - Setup
    $feature->setup(() ==> {
        $this->stack = new Stack();
    });

    //when block - Stimulus
    $feature->when(() ==> {
        $this->stack->add(1);
    });

    //then block - Response
    $feature->then(() ==> {
        invariant($this->stack->count() === 1, 'must have been added value');
    });
}
```

### Verify the specification

In the package root directory run the following command.  

	vendor/bin/hhspecify


Run the test
----------------------------

	composer install
	composer test

Run the example
----------------------------

	composer install
	composer example
