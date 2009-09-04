#include "bigint.ih"

BigInt &BigInt::operator=(BigInt const &other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}