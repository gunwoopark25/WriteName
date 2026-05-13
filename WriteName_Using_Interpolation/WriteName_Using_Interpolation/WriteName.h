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
    int Matrix_Size;

    double Min_x;
    double Min_y;
    double Max_x;
    double Max_y;
    double Max_u;
    double dx;
    double dy;

    double* u;
    double** Matrix;

    Point2D *POC;
    Point2D* CP;
    Point2D* All_POC;

    void openFile();
    void inputData();
    void ChordLength();
    void Normalization();
    void makeBersteinMatrix();
    void GaussJordanElimination();
    void MatrixMultiplication();
    void De_Casteljau();
    void solveNormalization();
    void writePS();
    void finalPS();
};
