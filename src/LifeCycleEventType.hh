<?hh //strict

namespace specify;

enum LifeCycleEventType : string
{
    VerifyStart = 'verifyStart';
    SpecificationVerifyStart = 'specificationVerifyStart';
    SpecificationVerifyFinish = 'specificationVerifyFinish';
    VerifyFinish = 'verifyFinish';
}
