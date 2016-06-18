#ifndef STUDENT_H
#define STUDENT_H

#include<fstream>
#include<iostream>
#include"CourseGrade.h"
#include"login.h"
class Administrator;
using namespace std;
class Student :public Login{
public:
	Student();
	void writeFileOfStudent(ofstream &of);//向文件中写入学生信息
	bool readFileOfStudent(ifstream &f);//从文件中读取学生信息
	void showSingleStudentInformation();//显示该学生信息
	void setInformation(string name, string no, int age, string sex, string add, CourseGrade score);//更新学生信息
	void updateStudentInformation(int, string);//更新学生信息
	string getName();
	string getNo();
	bool searchByNo(int);
	void queryStudentInformation(string);
	void changeStudentInformation(string);
	//登录模块
    void validate();
	void menu();
private:
	int age;//年龄
	string name, no, sex, address;//姓名,学号,性别,住址
	CourseGrade score;//成绩
	Administrator *pAdministrator;
	bool isCorrect(string);
};
#endif
