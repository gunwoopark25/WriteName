#include "WriteName.h"
#include <fstream>
#include <iostream>
#include <string>

void main()
{
	WriteName Bezier;

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> parent of e539a46 (1차 완료(이제 여기서 수정해야함))
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