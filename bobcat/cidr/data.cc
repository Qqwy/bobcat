#include "cidr.ih"

FBB::Pattern Cidr::s_pattern("\\b\\d+\\.\\d+\\.\\d+\\.\\d+\\b");
FBB::Pattern Cidr::s_empty("^\\s*(#.*)?$");