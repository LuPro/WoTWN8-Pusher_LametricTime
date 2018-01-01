#include "searchstat.h"

SearchStat::SearchStat()
{

}

SearchStat::SearchStat(const string &searchTermBegin, const string &searchTermEnd, const string &displayName, const string &postfix, const string &iconA, const string &iconB, const unsigned int &decimalPlaces) :
    searchTermBegin(searchTermBegin), searchTermEnd(searchTermEnd)
{
    this->displayName = displayName;
    this->postfix = postfix;
    this->iconA = iconA;
    this->iconB = iconB;
    this->decimalPlaces = decimalPlaces;
}
