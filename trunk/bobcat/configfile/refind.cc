#include "configfile.ih"

RE_iterator::iterator RE_iterator::find()
{
    return find_if(d_current, d_end, FnWrap1c<string &, RE_iterator &, bool>
                                     (reMatch, *this));
}
