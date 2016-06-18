#include"CourseGrade.h"
#include<string>
using namespace std;
string CourseGrade::getComputer(){
	return Computer;
}
string CourseGrade::getMath(){
	return Math;
}
string CourseGrade::getEnglish(){
	return English;
}
void CourseGrade::setComputer(string computer){
	this->Computer = computer;
}
void  CourseGrade::setMath(string math){
	this->Math = math;
}
void CourseGrade::setEnglish(string english){
	this->English = english;
}