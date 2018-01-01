#include "stat.h"

Stat::Stat()
{

}

Stat::Stat(const string &displayName, const string &postfix, const string &iconA, const string &iconB, const unsigned int &decimalPlaces) :
    displayName(displayName), postfix(postfix), iconA(iconA), iconB(iconB), decimalPlaces(decimalPlaces)
{

}
