#include "htmlparser.h"

HTMLParser::HTMLParser(const string &fileName, vector<SearchStat> stats) :
    fileName(fileName), stats(stats)
{
    init();
}

void HTMLParser::init()
{
    htmlFile.open(fileName);
    if (!htmlFile.is_open()) {
        cout << "[E] HTML File \"" << fileName << "\" could not be opened" << endl;
        cout << flush;
        exit(EXIT_FAILURE);
    }
}

void HTMLParser::parseFile()
{
    size_t posBegin, posEnd;
    string fileBuffer = loadFile();
    float value;

    for (size_t i = 0; i < stats.size(); i++) {
        posBegin = fileBuffer.find(stats.at(i).searchTermBegin);
        if (posBegin == string::npos) {
            cout << "[I] Could not find parameter \"" << stats.at(i).searchTermBegin << "\" (begin of \"" << stats.at(i).displayName << "\") in the HTML file \"" << fileName << "\", trying next parameter" << endl;
            stats.erase(stats.begin() + i);
            continue;
        }
        posBegin += stats.at(i).searchTermBegin.length();      //sets the position to AFTER the search term (off by 1 error?)

        posEnd = fileBuffer.find(stats.at(i).searchTermEnd);
        if (posEnd == string::npos) {
            cout << "[I] Could not find parameter \"" << stats.at(i).searchTermEnd << "\" (end of \"" << stats.at(i).displayName << "\") in the HTML file \"" << fileName << "\", trying next parameter" << endl;
            stats.erase(stats.begin() + i);
            continue;
        }
        posEnd -= 1;

        stringstream strValue(fileBuffer.substr(posBegin, posEnd));
        strValue >> value;

        stats.at(i).value = value;
    }
}

vector <Stat> HTMLParser::getStats()
{
    vector <Stat> returnStats;

    //loading stats with the search terms into a vector of stats without them
    //using object slicing
    for (SearchStat stat : stats) {
        Stat _stat = stat;
        returnStats.push_back(_stat);
    }
    return returnStats;
}

string HTMLParser::loadFile()
{
    string wholeFile;
    char buffer[MAX_LINE_LENGTH];

    wholeFile.clear();
    while (htmlFile.getline(buffer, MAX_LINE_LENGTH)) {
        wholeFile += buffer;
    }
    //while (htmlFile >> wholeFile);

    //cout << "html: " << wholeFile << endl;
    return wholeFile;
}
