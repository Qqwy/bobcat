#include "ofoldstreambuf.ih"

size_t OFoldStreambuf::length() const
{
    return d_next + d_wsLength + d_nonWs.length();
}
