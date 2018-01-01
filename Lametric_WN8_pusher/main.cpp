#include <iostream>

#include "htmlparser.h"
#include "searchstat.h"
#include "settingsparser.h"
#include "statsettingparser.h"
#include "pushscriptgenerator.h"

using namespace std;

int main()
{
    SettingsParser settings;

    settings.init();
    settings.readSettings();

    StatSettingParser statSettings(settings.getStatSettingsName());
    vector <SearchStat> wantedStats;

    statSettings.init();
    statSettings.parseFile();
    wantedStats = statSettings.getWantedStats();

    HTMLParser html(settings.getHTMLName(), wantedStats);

    html.parseFile();
    vector <Stat> actualStats = html.getStats();

    PushScriptGenerator scriptGen(settings.getPusherScriptName(), settings.getAccessToken(), settings.getPushURL(), actualStats);
    scriptGen.init();
    scriptGen.generateScript();

    return 0;
}
