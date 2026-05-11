#include "WriteName.h"
#include <fstream>
#include <iostream>
#include <string>

void main()
{
	WriteName Bezier;

<<<<<<< HEAD
	Bezier.fileLoad();
	for (int i = 0; i < 21; i++)
=======
	Bezier.fileOpen();
	for (int i = 0; i < 71; i++)
>>>>>>> 9f4ad39b589c6538d565dfa6f78f784af1110863
	{
		Bezier.inputData();
		Bezier.normalization();
	}
}