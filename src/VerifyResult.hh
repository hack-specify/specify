<?hh //strict

namespace specify;

interface VerifyResult
{
    public function getDescription() : string;
    public function isPassed() : bool;
    public function isFailed() : bool;
}
