#include "statsettingparser.h"

StatSettingParser::StatSettingParser()
{

}

StatSettingParser::StatSettingParser(const string &fileName) :
    fileName(fileName)
{

}

void StatSettingParser::init()
{
    inFile.open(fileName);
    if (!inFile.is_open()) {
        cout << "[E] Stat Settings File \"" << fileName << "\" could not be opened" << endl;
        cout << flush;
        exit(EXIT_FAILURE);
    }
}

void StatSettingParser::parseFile()
{
    char lineBuffer[MAX_STAT_SETTINGS_LINE_LENGTH];

    //maybe put those in a map for easier iteration
    char _searchTermBegin[MAX_PARAMETER_LENGTH];
    char _searchTermEnd[MAX_PARAMETER_LENGTH];
    char _displayName[MAX_PARAMETER_LENGTH];
    char _postfix[MAX_PARAMETER_LENGTH];
    char _iconA[MAX_PARAMETER_LENGTH];
    char _iconB[MAX_PARAMETER_LENGTH];
    char _decimalPlaces[MAX_PARAMETER_LENGTH];

    stats.clear();
    while (inFile.getline(lineBuffer, MAX_STAT_SETTINGS_LINE_LENGTH)) {
        sscanf(lineBuffer, "startConfine: %s <|> endConfine: %s <|> displayName: %s <|> postfix: %s <|> iconA: %s <|> iconB: %s <|> decimalPlaces: %s <|>", _searchTermBegin, _searchTermEnd, _displayName, _postfix, _iconA, _iconB, _decimalPlaces);
        string searchTermBegin(_searchTermBegin);
        string searchTermEnd(_searchTermEnd);
        string displayName(_displayName);
        string postfix(_postfix);
        string iconA(_iconA);
        string iconB(_iconB);
        string decimalPlaces(_decimalPlaces);

        replaceUnderscoreWithWS(searchTermBegin);
        replaceUnderscoreWithWS(searchTermEnd);
        replaceUnderscoreWithWS(displayName);
        replaceUnderscoreWithWS(postfix);
        replaceUnderscoreWithWS(iconA);
        replaceUnderscoreWithWS(iconB);
        replaceUnderscoreWithWS(decimalPlaces);

        stats.push_back(SearchStat(searchTermBegin, searchTermEnd, displayName, postfix, iconA, iconB, stoi(decimalPlaces)));
        //cout << "sT Begin: " << searchTermBegin << " sT End: " << searchTermEnd << " name: " << displayName << " postfix: " << postfix << " A: " << iconA << " B: " << iconB << endl;
    }
}

vector <SearchStat> StatSettingParser::getWantedStats()
{
    return stats;
}

void StatSettingParser::replaceUnderscoreWithWS(string &text)
{
    size_t underscorePos;
    while (1) {
        underscorePos = text.find("_");
        if (underscorePos == string::npos)
            break;

        text.at(underscorePos) = ' ';
    }
    if (text == " ")
        text.clear();
}
