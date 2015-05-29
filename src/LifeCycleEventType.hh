<?hh //strict

namespace minitest;

enum LifeCycleEventType : string
{
    VerifyStart = 'verifyStart';
    SpecificationVerifyStart = 'specificationVerifyStart';
    SpecificationVerifyFinish = 'specificationVerifyFinish';
    VerifyFinish = 'verifyFinish';
}
