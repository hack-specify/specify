<?hh //strict

namespace minitest;

use \ReflectionMethod;
use \Generator;

type SpecificationCollection = ImmVector<Specification<void>>;
type LifeCycleMessageSubscriberCollection = ImmVector<LifeCycleMessageSubscriber>;
type BehaviorMethodCollection = Generator<int, BehaviorMethod, void>;

type VerifyResultCollection = Vector<VerifyResult>;
