#include"Student.h"
#include"Administrator.h"
#include"CourseGrade.h"
#include<fstream>
#include<string>
#include<iostream>
#include <sstream>
#include<iomanip>

using namespace std;

#define MEMBER_NUMBER 8
#define MAX_SIZE 20
#define STUDENT_MODIFY 5
#define output (cout <<setiosflags(ios::left)<<setfill(' ')<<setw(20) )
#define cr setfill(' ') << setw(10)

Student::Student(){}
string Student::getName(){ return name; }
string Student::getNo(){ return no; }
extern void welcome();

void Student::setInformation(string name, string no, int age, string sex, string address, CourseGrade score)
{
	this->name = name;
	this->no = no;
	this->age = age;
	this->sex = sex;
	this->address = address;
	this->score = score;
}
void Student::updateStudentInformation(int type, string information){//输入学生信息这件事应该由学生类自己来做
	switch (type){
	case 3:
		no = information;//拿到学号
		while (true){
			output << "请输入年龄: ";
			std::cin >> this->age;
			if (age <= 200 && age >= 1){
				break;
			}
			else {
				cout << "你输入的年龄不合法" << endl;
			}
		}
		while (true){
			output << "请输入性别(男/女): ";
			std::cin >> this->sex;
			if (sex == "男" || sex == "女"){
				break;
			}
			else{
				cout << "你输入的性别有误!" << endl;
			}
		}
		
		output << "请输入宿舍地址: ";
		std::cin >> this->address;
		break;
	case 6:
		no = information;//拿到学号
		output << "请输入姓名: ";
		std::cin >> this->name;
		while (true){
			output << "请输入年龄: ";
			std::cin >> this->age;
			if (age <= 200 && age >= 1){
				break;
			}
			else {
				cout << "你输入的年龄不合法" << endl;
			}
		}
		while (true){
			output << "请输入性别(男/女): ";
			std::cin >> this->sex;
			if (sex == "男" || sex == "女"){
				break;
			}
			else{
				cout << "你输入的性别有误!" << endl;
			}
		}

		output << "请输入宿舍地址: ";
		std::cin >> this->address;

		string csgrade;
		while(true){
		output << "请输入计算机成绩: ";
		std::cin >> csgrade;
		if (isCorrect(csgrade)){
		break;
		}
		}
		this->score.setComputer(csgrade);

		string mathgrade;
		while (true){
		output << "请输入数学成绩: ";
		std::cin >> mathgrade;
		if (isCorrect(mathgrade)){
		break;
		}
		}

		this->score.setMath(mathgrade);
		string englishgrade;
		while (true){
		output << "请输入英语成绩: ";
		std::cin >> englishgrade;
		if (isCorrect(englishgrade)){
		break;
		}
		}
		this->score.setEnglish(englishgrade);
		break;
	}
}
bool Student::isCorrect(string grade){
	int sum = 0;
	int len = grade.length();
	for (int i = 0; i < len; i++){
		sum = sum * 10 + grade[i] - '0';
	}
	if (sum <= 100 && sum >= 0){
		return true;
	}
	else{
		cout << "你输入的分数非法!" << endl;
		return false;
	}
}
bool Student::readFileOfStudent(ifstream &f)//从文件读
{
	string str;
	getline(f, str,'\n');
	//if (合法)...
	istringstream istr(str);
	if (str == "") {//读取的是空行
		return false;
	}
	string sTmp[MEMBER_NUMBER];
	int i=0;
	while (!istr.eof())
	{
		istr >> sTmp[i++]; //get a word
	}
	if (i != 8) {//行错误
		return false;
	}
	(*this).name = sTmp[0];
	(*this).no = sTmp[1];
	int ageStringLength= sTmp[2].length();
	int ageActual=0;
	for (int i = 0; i < ageStringLength; i++) {
		ageActual = ageActual * 10 + (sTmp[2][i] - '0');
	}
	(*this).age = ageActual;
	(*this).sex = sTmp[3];
	(*this).address = sTmp[4];
	score.setComputer(sTmp[5]);
	score.setMath(sTmp[6]);
	score.setEnglish(sTmp[7]);
	return true;
}
void Student::writeFileOfStudent(ofstream &of)//向文件中写入
{
	of << " "<<this->name << " " << this->no << " " << this->age << " " 
		<< this->sex << " " << this->address << " " 
		<< this->score.getComputer() << " " 
		<< this->score.getEnglish() << " " 
		<< this->score.getMath() << endl;
}
void Student::validate(){
	output << "请输入用户名(学号):";
	this->pAdministrator = new Administrator;
	int type = 2;
	bool exist = true;
		exist = this->pAdministrator->searchByNo(type);
		if (!exist){
			cout << "你输入的用户名不存在!" << endl;
			pAdministrator->goOn();
			return;
		}
		else {//如果找到了
			(*this).menu();
		}
}
void Student::changeStudentInformation(string no){
	(*(*this).pAdministrator).showAllStudentInformation(STUDENT_MODIFY);
}
void Student::queryStudentInformation(string no){
	pAdministrator->showAllStudentInformation(2);
}
void Student::menu(){
	while (true) {
		welcome();
		
		std::cout << "  ╭--------------------------------------╮" << endl;
		std::cout << " │          1 查询信息                    │" << endl;
		std::cout << " │          2 修改信息                    │" << endl;
		std::cout << " │          3 退出登录                    │" << endl;
		std::cout << " ╰----------------------------------------╯" << endl;
		output << endl << "请选择:    ";
		char choose;
		std::cin >> choose;
		string noCurrent;
		switch (choose)
		{
		case '1': 
			noCurrent = this->pAdministrator->getNoTmp();
			queryStudentInformation(noCurrent);
			break;
		case '2':  
			changeStudentInformation(noCurrent);
			break;
		case '3':  
			return;
		default:
		{
				   std::cout << "请按规定输入选择项!" << endl;
				   pAdministrator->goOn();
				   menu();
		}
		}
	}
}
void Student::showSingleStudentInformation()
{
    Administrator::showLine();
	std::cout   << cr<< no << "│" 
				<< cr <<  name << "│" 
				<< cr <<  age << "│" 
				<< cr <<  sex << "│" 
				<< cr <<  address << "│" 
				<< cr <<  score.getComputer() << "│" 
				<< cr <<  score.getMath() << "│" 
				<< cr <<  score.getEnglish() << "│" << endl;
}