#ifndef STATSETTINGPARSER_H
#define STATSETTINGPARSER_H

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

#include "searchstat.h"

#define MAX_LINE_LENGTH 4096
#define MAX_PARAMETER_LENGTH 512

using namespace std;

class StatSettingParser
{
public:
    StatSettingParser();
    StatSettingParser(const string &fileName);

    void init();

    void parseFile();

    vector <SearchStat> getWantedStats();

private:
    ifstream inFile;
    string fileName;

    vector <SearchStat> stats;

    void replaceUnderscoreWithWS (string &text);
};

#endif // STATSETTINGPARSER_H
