#include "WriteName.h"
#include <fstream>
#include <iostream>
#include <string>

void main()
{
	WriteName Bezier;

	Bezier.fileLoad();
	for (int i = 0; i < 21; i++)
	{
		Bezier.inputData();
		Bezier.normalization();
	}
}