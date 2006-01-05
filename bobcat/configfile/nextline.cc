#include "configfile.ih"

bool ConfigFile::nextLine(istream &istr, string &line)
{
    while (getline(istr, line))
    {
        string::size_type pos = line.find_first_not_of(" \t");
        if (pos != string::npos)                    // remove initial ws.
            line.erase(0, pos);

        if (d_rmComment)
            removeComment(line);

        while (true)
        {
            unsigned lastChar = line.length() - 1;   // the last char
    
            if (line[lastChar] != '\\')             // not '\\' ?
                break;                              // then done here

            line.erase(lastChar);                   // erase the last char
            append_next(istr, line);                // append the next line
        }

        if (hasContent(line))                       // any content on this?
        {
            removeTrailingBlanks(line);
            return true;
        }
    }
    line.erase();
    return false;                       // no more lines
}   
