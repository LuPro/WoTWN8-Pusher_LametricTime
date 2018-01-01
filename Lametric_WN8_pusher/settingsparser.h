#ifndef SETTINGSPARSER_H
#define SETTINGSPARSER_H

#include <fstream>
#include <string>
#include <iostream>

#define SETTINGSFILE_NAME "settings.dat"

using namespace std;

class SettingsParser
{
public:
    SettingsParser();

    //opens the settings file
    void init();

    //reads and parses the settings file
    void readSettings();

    inline string getHTMLName () {
        return htmlName;
    }
    inline string getPusherScriptName () {
        return pusherScriptName;
    }
    inline string getStatSettingsName () {
        return statSettingsName;
    }
    inline string getPushURL () {
        return pushURL;
    }
    inline string getAccessToken () {
        return accessToken;
    }

private:
    ifstream settingsFile;

    string htmlName, pusherScriptName, statSettingsName;
    string pushURL, accessToken;
};

#endif // SETTINGSPARSER_H
