#include "argconfig.ih"

    // return ConfigFile's RE_iterator to the configfile's long option

std::unordered_map<int, std::string>::const_iterator 
    ArgConfig__::find(int optChar) const
{
    return d_longOption.find(optChar);
}

pair<ArgConfig::const_RE_iterator, ArgConfig::const_RE_iterator> 
    ArgConfig::findLongOption(int optChar)
{
            // find the long option given the short option char
    auto optIt = d_ptr->find(optChar);

    return optIt == d_longOption.end() ?        // not found,
                        beginEndRE()
                    :                           // else return an iter to the
                        longConfigOpt(optIt->second);   // option's line.
}
