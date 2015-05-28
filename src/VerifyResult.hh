<?hh //strict

namespace minitest;

interface VerifyResult
{
    public function getDescription() : string;
    public function isPass() : bool;
    public function isFailed() : bool;
}
