<?hh //strict

namespace minitest;

use \ReflectionMethod;
use \Generator;

type ObjectBehaviorSpecification = Specification<BehaviorResult>;

type SpecificationCollection = ImmVector<ObjectBehaviorSpecification>;
type LifeCycleMessageSubscriberCollection = ImmVector<LifeCycleMessageSubscriber>;
type BehaviorMethodCollection = Generator<int, BehaviorMethod, void>;

type VerifyResultCollection = Vector<VerifyResult>;

type MethodBehaviorResultCollection = Vector<MethodBehaviorResult>;
