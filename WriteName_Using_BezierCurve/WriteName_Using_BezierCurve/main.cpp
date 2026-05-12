#include "WriteName.h"
#include <fstream>
#include <iostream>
#include <string>

void main()
{
	WriteName Bezier;

	Bezier.fileLoad();
	for (int i = 0; i < 71; i++)
	{
		Bezier.inputData();
		Bezier.normalization();
		Bezier.De_Casteljau();
		Bezier.solveNormalization();
		Bezier.writePS();
	}
	Bezier.finalPS();
}