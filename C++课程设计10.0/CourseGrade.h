#pragma once

#include<iostream>
using namespace std;
class CourseGrade
{

public :
	string getComputer();
	string getMath();
	string getEnglish();
	void setComputer(string );
	void setMath(string );
	void setEnglish(string);
private:
	string Computer;
	string Math;
	string English;
};