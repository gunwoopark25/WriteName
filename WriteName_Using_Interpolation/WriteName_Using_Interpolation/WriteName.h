#pragma once
#include "Point2D.h"
#include <fstream>
#include <iostream>

using namespace std;

class WriteName
{
private:
    ifstream readFile;
    ofstream psFile;

public:
    WriteName();
    ~WriteName();

    int Parameter;
    int Degree;
    int POC_Size;

    Point2D *POC;

    void openFile();

};
