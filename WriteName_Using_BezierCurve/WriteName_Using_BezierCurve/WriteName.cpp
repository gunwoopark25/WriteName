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

    CP = new Point2D[Degree + 1];
}

void WriteName::fileLoad()
{
    readFile.open("u.txt");
}

void WriteName::inputData()
{
    for (int k = 0; k <= Degree; k++)
    {
        readFile >> CP[k].x;
        readFile >> CP[k].y;
    }
}

void WriteName::normalization()
{
    Min_x = CP[0].x;
    Min_y = CP[0].y;
    Max_x = CP[0].x;
    Max_y = CP[0].y;

    for (int k = 0; k <= Degree; k++)
    {
        if (Min_x > CP[k].x)
        {
            Min_x = CP[k].x;
        }
        if (Min_y > CP[k].y)
        {
            Min_y = CP[k].y;
        }
        if (Max_x < CP[k].x)
        {
            Max_x = CP[k].x;
        }
        if (Max_y < CP[k].y)
        {
            Max_y = CP[k].y;
        }
    }

    dx = Max_x - Min_x;
    dy = Max_y - Min_y;

    for (int k = 0; k <= Degree; k++)
    {
        CP[k].x = (CP[k].x - Min_x) / dx;
        CP[k].y = (CP[k].y - Min_y) / dy;
    }
}

void WriteName::De_Casteljau()
{
    Point2D* Coordinate = new Point2D[POC_Size];
    All_POC = new Point2D[Parameter + 1];

    for (int k = 0; k <= Parameter; k++)
    {
        double t = (double)k / Parameter;
        int boundary = 0;

        for (int j = 1; j <= Degree; j++)
        {
            int n = Degree - j + 1;
            int start_X = boundary + 1;
            int end_X = boundary + n + 1;

            for (int X = start_X; X < end_X; X++)
            {
                
            }
        }
    }
}