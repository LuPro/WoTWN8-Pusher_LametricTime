#ifndef STAT_H
#define STAT_H

#include <string>

using namespace std;

struct Stat
{
public:
    Stat();
    Stat(const string &displayName, const string &postfix, const string &iconA, const string &iconB, const unsigned int &decimalPlaces);

    string displayName = "###";
    float value = 0;
    string postfix = "";
    string iconA = "i0000";
    string iconB = "i0000";
    unsigned int decimalPlaces = 0;
};

#endif // STAT_H
