<?hh //strict

namespace minitest;

use \ReflectionMethod;
use \Generator;

type SpecificationCollection = ImmVector<Specification>;
type LifeCycleMessageSubscriberCollection = ImmVector<LifeCycleMessageSubscriber>;
type MethodCollection = Generator<int, ReflectionMethod, void>;
