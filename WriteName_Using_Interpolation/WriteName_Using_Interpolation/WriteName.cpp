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
    
    POC = new Point2D[Degree+1];

	Matrix = new double* [Degree + 1];
	for (int k = 0; k <= Degree; k++)
	{
		Matrix[k] = new double[Degree * 2 + 2];
	}

	Matrix_Size = Degree * 2 + 2;

	CP = new Point2D[Degree + 1];
}

WriteName::~WriteName()
{
    readFile.close();
    psFile.close();
}

void WriteName::openFile()
{
    readFile.open("u.txt");
    psFile.open("Name.ps");

    psFile << "%!PS" << endl;
}

void WriteName::inputData()
{
    for (int k = 0; k <= Degree; k++)
    {
        readFile >> POC[k].x;
        readFile >> POC[k].y;
    }
}

void WriteName::ChordLength()
{
    u = new double[Degree + 1];
    double* l = new double[Degree];

    u[0] = 0;
    for (int k = 1; k <= Degree; k++)
    {
        l[k - 1] = sqrt(pow(POC[k].x - POC[k - 1].x, 2) + pow(POC[k].y - POC[k - 1].y, 2));
    }

    for (int k = 1; k <= Degree; k++)
    {
        u[k] = u[k - 1] + l[k - 1];
    }
}

void WriteName::Normalization()
{
	Min_x = POC[0].x;
	Min_y = POC[0].y;
	Max_x = POC[0].x;
	Max_y = POC[0].y;
	Max_u = u[0];
	/*--- 최대/최소값 찾기 ---*/
	for (int k = 0; k <= Degree; k++)
	{
		/*--- 최솟값 찾기 ---*/
		if (Min_x > POC[k].x)
		{
			Min_x = POC[k].x;
		}
		if (Min_y > POC[k].y)
		{
			Min_y = POC[k].y;
		}
		/*--- 최댓값 찾기 ---*/
		if (Max_x < POC[k].x)
		{
			Max_x = POC[k].x;
		}
		if (Max_y < POC[k].y)
		{
			Max_y = POC[k].y;
		}
		if (Max_u < u[k])
		{
			Max_u = u[k];
		}
	}

	dx = Max_x - Min_x;
	dy = Max_y - Min_y;

	for (int k = 0; k <= Degree; k++)
	{
		/*--- POC 정규화 ---*/
		POC[k].x = (POC[k].x - Min_x) / dx;
		POC[k].y = (POC[k].y - Min_y) / dy;

		/*--- Chord Length 정규화 ---*/
		u[k] = u[k] / Max_u;
	}
}

void WriteName::makeBersteinMatrix()
{
	for (int m = 0; m <= Degree; m++)
	{
		for (int j = 0; j <= Degree; j++)
		{
			int Degreep = 1;
			int jp = 1;
			int Degree_jp = 1;

			for (int k = 1; k <= Degree; k++)
			{
				Degreep *= k;
			}
			for (int k = 1; k <= j; k++)
			{
				jp *= k;
			}

			int Degree_j = Degree - j;
			for (int k = 1; k <= Degree_j; k++)
			{
				Degree_jp *= k;
			}
			double nCr = Degreep / (jp * Degree_jp);

			/*--- Bernstein Polynomial ---*/
			Matrix[m][j] = nCr * pow(1 - u[m], Degree - j) * pow(u[m], j);
		}
	}
}

void WriteName::GaussJordanElimination()
{
	for (int m = 0; m <= Degree; m++)
	{
		for (int n = Degree + 1; n < Degree * 2 + 2; n++)
		{
			if (m == n - Degree - 1)
			{
				Matrix[m][n] = 1;
			}
			else
			{
				Matrix[m][n] = 0;
			}
		}
	}

	for (int m = 0; m <= Degree; m++)
	{
		double Set2 = Matrix[m][m];
		for (int j = 0; j <= Matrix_Size - 1; j++)
		{
			Matrix[m][j] /= Set2;
		}

		for (int k = 0; k <= Degree; k++)
		{
			if (k != m)
			{
				double factor = Matrix[k][m];
				if (factor != 0)
				{
					for (int j = 0; j <= Matrix_Size - 1; j++)
					{
						Matrix[k][j] -= Matrix[m][j] * factor;
					}
				}
			}
		}
	}
}

void WriteName::MatrixMultiplication()
{
	for (int m = 0; m <= Degree; m++)
	{
		/*--- 변수 초기화 ---*/
		double Sum_x = 0;
		double Sum_y = 0;

		/*--- 행렬 곱 ---*/
		for (int j = 0; j <= Degree; j++)
		{
			Sum_x += Matrix[m][Degree + 1 + j] * POC[j].x;
			Sum_y += Matrix[m][Degree + 1 + j] * POC[j].y;
		}

		/*--- 값 저장 ---*/
		CP[m].x = Sum_x;
		CP[m].y = Sum_y;
	}
}

void WriteName::De_Casteljau()
{
	Point2D* Coordinate = new Point2D[POC_Size];
	All_POC = new Point2D[Parameter + 1];

	/*--- CP를 Coordinate 초기값으로 복사 ---*/
	for (int j = 0; j <= Degree; j++)
	{
		Coordinate[j].x = CP[j].x;
		Coordinate[j].y = CP[j].y;
	}

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
				Coordinate[X + n].x = (1 - t) * Coordinate[X - 1].x + t * Coordinate[X].x;
				Coordinate[X + n].y = (1 - t) * Coordinate[X - 1].y + t * Coordinate[X].y;
			}
			boundary += (Degree + 1 - j + 1);
		}

		int last_X = POC_Size - 1;
		All_POC[k].x = Coordinate[last_X].x;
		All_POC[k].y = Coordinate[last_X].y;
	}
}

void WriteName::solveNormalization()
{
	for (int k = 0; k <= Degree; k++)
	{
		CP[k].x = CP[k].x * dx + Min_x;
		CP[k].y = CP[k].y * dy + Min_y;

		POC[k].x = POC[k].x * dx + Min_x;
		POC[k].y = POC[k].y * dy + Min_y;
	}

	for (int k = 0; k <= Parameter; k++)
	{
		All_POC[k].x = All_POC[k].x * dx + Min_x;
		All_POC[k].y = All_POC[k].y * dy + Min_y;
	}
}

void WriteName::writePS()
{
	psFile << "newpath" << endl;
	for (int k = 0; k <= Parameter; k++)
	{
		if (k == 0)
		{
			psFile << All_POC[k].x << " " << All_POC[k].y << " " << "moveto" << endl;
		}
		else
		{
			psFile << All_POC[k].x << " " << All_POC[k].y << " " << "lineto" << endl;
		}
	}
	psFile << "stroke" << endl;
}

void WriteName::finalPS()
{
	psFile << "showpage" << endl;
}