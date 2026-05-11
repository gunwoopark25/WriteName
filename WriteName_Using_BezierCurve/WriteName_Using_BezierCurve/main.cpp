#include "WriteName.h"
#include <fstream>
#include <iostream>
#include <string>

void main()
{
	WriteName Bezier;

	Bezier.fileOpen();
	for (int i = 0; i < 21; i++)
	{
		Bezier.inputData();
		Bezier.normalization();
		Bezier.De_Casteljau();
		Bezier.solveNormalization();
		Bezier.writePS();
	}
	Bezier.finalPS();
}