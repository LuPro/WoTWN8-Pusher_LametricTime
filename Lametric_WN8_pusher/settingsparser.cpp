#include "settingsparser.h"

SettingsParser::SettingsParser()
{

}

void SettingsParser::init()
{
    settingsFile.open(SETTINGSFILE_NAME);
    if (!settingsFile.is_open()) {
        cout << "[E] Settings File \"" << SETTINGSFILE_NAME << "\" could not be opened" << endl;
        cout << flush;
        exit(EXIT_FAILURE);
    }
}

void SettingsParser::readSettings()
{
    string buffer;
    int i = 0;
    while (settingsFile >> buffer) {
        switch (i) {
        case 0:
            htmlName = buffer;
            break;
        case 1:
            pusherScriptName = buffer;
            break;
        case 2:
            statSettingsName = buffer;
            break;
        case 3:
            pushURL = buffer;
            break;
        case 4:
            accessToken = buffer;
            break;
        default:
            break;
        }
        i++;
    }
}
