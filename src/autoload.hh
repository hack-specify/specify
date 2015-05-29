<?hh //strict

namespace minitest;

use \ReflectionMethod;
use \Generator;

type ObjectBehaviorSpecification = Specification<ObjectBehaviorResult>;

type SpecificationCollection = ImmVector<ObjectBehaviorSpecification>;
type LifeCycleMessageSubscriberCollection = ImmVector<LifeCycleMessageSubscriber>;
type BehaviorMethodCollection = Generator<int, BehaviorMethod, void>;

type VerifyResultCollection = Vector<VerifyResult>;

type MethodBehaviorResultCollection = Vector<MethodBehaviorResult>;
