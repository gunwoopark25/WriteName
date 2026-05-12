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
	/*--- 생성자 ---*/
	WriteName();

	/*--- 소멸자 ---*/
	~WriteName();

	/*--- 1차원 변수 ---*/
	int Parameter;
	int Degree;
	int POC_Size;

	double Min_x;
	double Min_y;
	double Max_x;
	double Max_y;
	double dx;
	double dy;

	/*--- Point2D ---*/
	Point2D* CP;
	Point2D* All_POC;

	/*--- 함수 ---*/
	void fileLoad();
	void inputData();
	void normalization();
	void De_Casteljau();
	void solveNormalization();
	void writePS();
	void finalPS();

};