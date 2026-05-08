#include "WriteName.h"
#include "Point2D.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

WriteName::WriteName()
{
    Parameter = 100;
    Degree = 3;
}

void WriteName::fileLoad()
{
    ifstream readfile("u.txt");
    if (!readfile)
    {
        cout << "This File can't open" << endl;
        return;
    }


}
