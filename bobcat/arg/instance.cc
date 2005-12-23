#include "arg.ih"

Arg &Arg::instance() throw (Errno)
{
    if (!s_arg)
        throw Errno("Arg::instance(): not yet initialized");

    return *s_arg;
}