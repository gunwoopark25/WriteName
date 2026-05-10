#include "WriteName.h"
#include "Point2D.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

WriteName::WriteName()
{
<<<<<<< HEAD
	Parameter = 10;
	Degree = 3;
=======
    Parameter = 100;
    Degree = 3;
>>>>>>> 24dd5a2a195f22f30c8cd0e77c0fd29b74f2e50e
}

void WriteName::fileLoad()
{
<<<<<<< HEAD
	ifstream readFile("우.txt");

    /*--- 호출이 안됬을 경우 ---*/
    if (!readFile)
    {
        cout << "You can't load this file." << endl;
        return;
    }
}
=======
    ifstream readfile("u.txt");
    if (!readfile)
    {
        cout << "This File can't open" << endl;
        return;
    }


}
>>>>>>> 24dd5a2a195f22f30c8cd0e77c0fd29b74f2e50e
