#pragma once
#include <vector>
using namespace std;
class parallelogram
{ 
private:
	float first_side;
	float second_side;
	float angle;
public:
	parallelogram(float first_side, float second_side, float angle);
	parallelogram (parallelogram const& other);
	static void initVector(vector<parallelogram> &v, const int n, vector<float> &s, int &i);
	float GetFirstSide();
	float GetSecondSide();
	float GetAngle();
	float resizing_first_side(float);
	float resizing_second_side(float);
	float perimetr();
	float area();
	float first_diagonal();
	float second_diagonal();
	float first_height();
	float second_height();
};

