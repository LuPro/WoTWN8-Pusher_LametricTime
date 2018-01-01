#include "pushscriptgenerator.h"

PushScriptGenerator::PushScriptGenerator()
{

}

PushScriptGenerator::PushScriptGenerator(const string &scriptFileName, const string &accessToken, const string &pushURL, vector<Stat> stats) :
    scriptFileName(scriptFileName), accessToken(accessToken), pushURL(pushURL), stats(stats)
{

}

void PushScriptGenerator::init()
{
    scriptFile.open(scriptFileName);
    if (!scriptFile.is_open()) {
        cout << "[E] Script File \"" << scriptFileName << "\" could not be opened" << endl;
        cout << flush;
        exit(EXIT_FAILURE);
    }
}

void PushScriptGenerator::generateScript ()
{
    //start of the script
    string scriptStart = "curl -X POST \\\n"
                         "-H \"Accept: application/json\" \\\n"
                         "-H \"X-Access-Token: ";
    //between Token and frames
    string betweenTF = "\" \\\n"
                       "-H \"Cache-Control: no-cache\" \\\n"
                       "-d \'{\n"
                       "\t\"frames\": [\n";
    //end of the script
    string scriptEnd = "]\n"
                       "}\' \\\n";

    string pusherScript = scriptStart + accessToken + betweenTF;

    for (size_t i = 0; i < stats.size(); i++) {
        char valBuffer[64];
        sprintf(valBuffer, "%.*f", stats.at(i).decimalPlaces, stats.at(i).value);
        string value(valBuffer);
        pusherScript += generateFrame(stats.at(i).displayName, "", stats.at(i).iconA, i*2, stats.size()*2-1);
        pusherScript += generateFrame(value, stats.at(i).postfix, stats.at(i).iconB, (i*2)+1, stats.size()*2-1);
    }

    pusherScript += scriptEnd + pushURL;

    //write generated script into file
    scriptFile << pusherScript;

}

string PushScriptGenerator::generateFrame(const string &text, const string &postfix, const string &icon, const int &frameID, const int &lastFrameID)
{
    //delemiter between frames (only between two frames, not before first and not after last)
    string frameDelim = "";
    if (!(frameID == lastFrameID))
        frameDelim = ",";

    //start of the frame
    string frameStart = ""
                        "\t\t{\n"
                        "\t\t\t\"text\": \"";
    //between text and icon
    string betweenTI = "\",\n"
                       "\t\t\t\"icon\": \"";
    //between icon and index
    string betweenII = "\",\n"
                       "\t\t\t\"index\": ";
    //end of the frame
    string frameEnd = "\n"
                       "\t\t}" + frameDelim + "\n";

    return frameStart + text + postfix + betweenTI + icon + betweenII + to_string(frameID) + frameEnd;
}
