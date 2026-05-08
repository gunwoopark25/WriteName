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
}

void WriteName::fileLoad()
{
	ifstream readFile("우.txt");

    /*--- 호출이 안됬을 경우 ---*/
    if (!readFile)
    {
        cout << "You can't load this file." << endl;
        return;
    }
}