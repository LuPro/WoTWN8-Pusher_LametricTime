#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "searchstat.h"

#define MAX_LINE_LENGTH 65536

using namespace std;

class HTMLParser
{
public:
    //runs init, sets all the wanted Stats in the vector
    HTMLParser(const string &fileName, vector<SearchStat> stats);

    //opens the html file
    void init();

    //reads through the contents of the HTML file and saves all stats defined in the vector "stats"
    void parseFile();

    //returns all stats with current value
    vector <Stat> getStats();

private:
    ifstream htmlFile;
    string fileName;

    vector <SearchStat> stats;

    string loadFile();
};

#endif // HTMLPARSER_H
