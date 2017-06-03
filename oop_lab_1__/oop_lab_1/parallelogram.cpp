#include "stdafx.h"
#include "parallelogram.h"
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;


	
parallelogram::parallelogram(float first_side, float second_side, float angle)
	: first_side(first_side), second_side(second_side), angle(angle)
{
	
}

void parallelogram::initVector(vector<parallelogram> &v, const int n, vector<float> &s, int&ind)
{
	for (int i = 0; i < n; ++i) {
		float first_side = s[ind++];
		float second_side = s[ind++];
		float angle = s[ind++];
		parallelogram temp(first_side, second_side, angle);
		v.insert(v.end(), temp);
	}
	//ind--;
}
parallelogram::parallelogram(parallelogram const & other)
{
	this->first_side = other.first_side;
	this->second_side = other.second_side;
	this->angle = other.angle;
}
float parallelogram::GetFirstSide()
{
	return first_side;
}

float parallelogram::GetSecondSide()
{
	return second_side;
}

float parallelogram::GetAngle()
{
	return angle*3.14 / 180;
}

float parallelogram::resizing_first_side(float k)
{
	first_side=first_side*k;
	return first_side;
}
float parallelogram::resizing_second_side(float k)
{
	second_side = second_side*k;
	return second_side;
}
float parallelogram::perimetr()
{
	 double p = (2 * (first_side + second_side));
	return p;
}
float parallelogram::area()
{
	double a = abs(first_side*second_side*sin(angle*3.14 / 180));
	return a;
}
float parallelogram::first_height()
{
	double h = abs(second_side*sin(angle*3.14 / 180));
	return h;
}
float parallelogram::second_height()
{
	double h = abs(first_side*sin(angle*3.14 / 180));
	return h;
}
float parallelogram::first_diagonal()
{
	double d = abs(sqrt(first_side*first_side + second_side*second_side - 2 * second_side*first_side*cos(angle*3.14 / 180)));
	return d;
}
float parallelogram::second_diagonal()
{
	double d = abs(sqrt(first_side*first_side + second_side*second_side + 2 * second_side*first_side*cos(angle*3.14 / 180)));
	return d;
}