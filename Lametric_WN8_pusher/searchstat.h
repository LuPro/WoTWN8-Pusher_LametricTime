#ifndef SEARCHSTAT_H
#define SEARCHSTAT_H

#include "stat.h"

struct SearchStat : public Stat
{
public:
    SearchStat();
    SearchStat(const string &searchTermBegin, const string &searchTermEnd, const string &displayName, const string &postfix, const string &iconA, const string &iconB, const unsigned int &decimalPlaces);

    string searchTermBegin, searchTermEnd;
};

#endif // SEARCHSTAT_H
