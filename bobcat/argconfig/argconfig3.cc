#include "argconfig.ih"

ArgConfig::ArgConfig(char const *optstring,
    LongOption const *begin, LongOption const *const end, 
    int argc, char **argv,
    Comment cType, SearchCasing sType, Indices iType)
:
    Arg(optstring, begin, end, argc, argv),
    ConfigFile(cType, sType, iType),
    d_ptr(new ArgConfig__(begin, end))      // 5
{}
