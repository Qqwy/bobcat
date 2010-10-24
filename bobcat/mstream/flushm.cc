#include "mstream.ih"

namespace FBB
{

std::ostream &flushm(std::ostream &os)
{
    os.flush();
    if (Mstream *mp = dynamic_cast<Mstream *>(&os))
    {
        os.clear();

        if (mp->throws())
            throw Errno(mp->id(), "FBB::Mstream");

        if (mp->lineExcess())
            throw Errno(mp->id()) << "Exceeding max. # of " << 
                        mp->maxCount() << " messages";
    }
    return os;
}

} // FBB
