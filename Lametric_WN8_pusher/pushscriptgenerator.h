#ifndef PUSHSCRIPTGENERATOR_H
#define PUSHSCRIPTGENERATOR_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>

#include <stat.h>

using namespace std;

class PushScriptGenerator
{
public:
    PushScriptGenerator();
    PushScriptGenerator(const string &scriptFileName, const string &accessToken, const string &pushURL, vector <Stat> stats);

    void init();

    void generateScript();

private:
    ofstream scriptFile;
    string scriptFileName;

    string accessToken;
    string pushURL;
    vector <Stat> stats;

    //generates the string for a frame
    string generateFrame (const string &text, const string &postfix, const string &icon, const int &frameID, const int &lastFrameID);
};

#endif // PUSHSCRIPTGENERATOR_H
