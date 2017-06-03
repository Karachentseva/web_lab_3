// oop_lab_1.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <list>
#include<vector>
#include "parallelogram.h"


void PerformAction(vector<float> choose, int& ind, vector<parallelogram>&v)
{
	int i;
	string s;
	double k;
	switch ((int)choose[ind++])
	{
	case 1:
		i = choose[ind++];
		k = choose[ind++];
		cout << "<h2> Изменение первой стороны: " << v[i].resizing_first_side(k) << "</h2>\n";
		break;
	case 2:
		 i= choose[ind++];
		k = choose[ind++];
		cout << "<h2>Изменение второй стороны: " << v[i].resizing_second_side(k)<< "</h2>\n";
		break;
	case 3:
		i = choose[ind++];
		cout << "<h2>Периметр: " << v[i].perimetr() << "</h2>\n";
		break;
	case 4:
		i = choose[ind++];
		cout << "<h2>Площадь: " << v[i].area() << "<\h2>\n";
		break;
	case 5:
		i = choose[ind++];
		cout << "<h2> Первая сторона: " << v[i].GetFirstSide() << "<\h2>\n";
		break;
	case 6:
		i = choose[ind++];
		cout << "<h2> Вторая сторона: " << v[i].GetSecondSide() << "<\h2>\n";
		break;
	case 7:
		i = choose[ind++];
		cout << "<h2> Первая диагональ: " << v[i].first_diagonal() << "<\h2>\n";
		break;
	case 8:
		i = choose[ind++];
		cout << "<h2> Вторая диагональ: " << v[i].second_diagonal() << "<\h2>\n";
		break;
	default:
		break;
	}

}

vector<float> Parse(char* s)
{
	int i = 0;
	vector<float> vec;
	string str = "";
	while (s[i] != '\0')
	{
		if (s[i] != '?') {
			str += s[i];
			++i;
		}
		else
		{
			vec.push_back(atof(str.c_str()));
			str = "";
			++i;
		}
	}
	vec.push_back(atof(str.c_str()));
	return vec;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n = 3;
	char* s = getenv("QUERY_STRING");
	s = "1?3?90?1?6?30?2?2?45?2?0?10?3?0";
	int ind = 0;
	auto params = Parse(s);
	vector<parallelogram> v;
	parallelogram::initVector(v, n, params, ind);
	cout << "Content-type:text/html\r\n\r\n";
	cout << "<html>\n";
	cout << "<head>\n";
	cout << "<title>Hello World - First CGI Program</title>\n";
	cout << "</head>\n";
	cout << "<body>\n";
	cout << "<h2>" << s << "</h2>";
	cout << "<h2>";
	for (int i = 0; i < params.size(); i++)
		cout << params[i] << " ";
	cout << "</h2>";
	while (ind<params.size())
	{
		PerformAction(params, ind, v);
		//++ind;
	}
	cout << "</body>\n";
	cout << "</html>\n";
	return 0;
}

//
////void parallelogram::get(int n)
////{
////		cout << "Введите первую сторону паралелограмма: " << endl;
////		cin >> first_side;
////		cout << "Введите вторую сторону паралелограмма: " << endl;
////		cin >> second_side;
////		cout << "Введите угол между ними:" << endl;
////		cin >> angle;
////}
//
//	
//	
//		}
//system("pause");
//	}
//}
//
//
//
