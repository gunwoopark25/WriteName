#include "WriteName.h"

void main()
{
    WriteName Interpolation;
    
    Interpolation.openFile();
    for (int i = 0; i < 100; i++)
    {
        Interpolation.inputData();
        Interpolation.ChordLength();
        Interpolation.Normalization();
        Interpolation.makeBersteinMatrix();
        Interpolation.GaussJordanElimination();
        Interpolation.MatrixMultiplication();
        Interpolation.De_Casteljau();
        Interpolation.solveNormalization();
        Interpolation.writePS();
    }
    Interpolation.finalPS();
}