#include "msgstreambuf.ih"

std::streamsize MsgStreambuf::xsputn(char const *buf, std::streamsize n)
{
    d_ostr->write(buf, n);
    return n;               // only if the write succeeded
}
