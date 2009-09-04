#include "bigint.ih"

BigInt const BigInt::pseudoRand(size_t size, Msb msb, Lsb lsb)
{
    BigInt ret;
    if (BN_pseudo_rand(&ret.d_bn, size, msb, lsb) != 1)
        throw Errno("BigInt::pseudoRand() failed");
    return ret;
}