#include "WriteName.h"
#include "Point2D.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

WriteName::WriteName()
{
    Parameter = 10;
    Degree = 3;
    POC_Size = Degree + 1;
    for (int k = Degree; k > 0; k--)
    {
        POC_Size = POC_Size + k;
    }
    
    POC = new Point2D[Degree+1];
}

WriteName::~WriteName()
{
    readFile.close();
    psFile.close();
}

void WriteName::openFile()
{
    readFile.open("u.txt");
    psFile.open("Name.ps");

    psFile << "%!PS" << endl;
}

