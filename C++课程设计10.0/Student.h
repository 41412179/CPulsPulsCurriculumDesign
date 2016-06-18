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
	void writeFileOfStudent(ofstream &of);//���ļ���д��ѧ����Ϣ
	bool readFileOfStudent(ifstream &f);//���ļ��ж�ȡѧ����Ϣ
	void showSingleStudentInformation();//��ʾ��ѧ����Ϣ
	void setInformation(string name, string no, int age, string sex, string add, CourseGrade score);//����ѧ����Ϣ
	void updateStudentInformation(int, string);//����ѧ����Ϣ
	string getName();
	string getNo();
	bool searchByNo(int);
	void queryStudentInformation(string);
	void changeStudentInformation(string);
	//��¼ģ��
    void validate();
	void menu();
private:
	int age;//����
	string name, no, sex, address;//����,ѧ��,�Ա�,סַ
	CourseGrade score;//�ɼ�
	Administrator *pAdministrator;
	bool isCorrect(string);
};
#endif
