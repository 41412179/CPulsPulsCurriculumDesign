
#include"Administrator.h"
#include"CourseGrade.h"
#include"Student.h"
#include<fstream>
#include<ctime>
#include<windows.h>
#include<cstring>
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;

#define SHOW_ALL_STUDENT_INFORMATION 1
#define EXITST_NO 2
#define STUDENT_MODIFY 5
#define ADMINISTRATOR_MODIFY 6
#define output (cout <<setiosflags(ios::left)<<setfill(' ')<<setw(20) )
#define cr     setfill(' ') << setw(12)

extern void welcome();

Administrator::~Administrator()
{
}

void Administrator::add()                           //录入学生信息函数
{
	string chooseyes;
	int choose;
	system("cls");
	do{
		std::cout << "请输入您要添加的学生信息:" << endl;
		output << "请输入学号: ";
		bool exist = false;
		exist = searchByNo(EXITST_NO);//2表示add(),如果已经存在该序号就返回true
		//s代表学号
		if (!exist){
			int type = 3;
			Student *p = new Student();
			p->updateStudentInformation(type, this->getNoTmp());//输入添加的学生信息
			list<Student>::iterator begin, end, i;
			begin = student.begin();
			end = student.end();
			bool insert_ = false;
			for (i = begin; i != end; i++){
				if ((*i).getNo() > this->getNoTmp()){
					student.insert(i, *p);
					insert_ = true;
					break;
				}
			}
			if (!insert_){
				student.push_back(*p);
			}
		}
		else {//如果该学生存在
			cout << "该学生已存在，请核对信息后再来添加!\n\n";
			std::cout << "1.返回主菜单\n2.继续添加 ------- ";
			std::cin >> choose;
			while (choose != 1 && choose != 2)
			{
				std::cout << "1.返回主菜单\n2.继续添加 ------- ";
				std::cin >> choose;
			}
			if (choose == 1)
				menu();
			else if (choose == 2)
				add();
		}
		int flag = 0;
		while (true){
			std::cout << "是否继续输入信息?(Y\\N) ------- ";
			std::cin >> chooseyes;
			if (chooseyes == "y" || chooseyes == "Y" || chooseyes == "yes"){
				flag = 1;
				break;
			}
			else {
				if (chooseyes == "n" || chooseyes == "N" || chooseyes == "no"){
					flag = 2;
					break;
				}
				else {
					cout << "你的输入有误!!!" << endl;
					flag = 3;
				}
			}
		}
		bool exit = false;
		switch (flag){
		case 1:
			continue;
			break;
		case 2:
			exit = true;
			break;
		default:
			break;
		}
		if (exit){
			break;
		}
	} while (true);
	save();
	menu();
}

Administrator::Administrator()
{
}

void Administrator::delete_()           //删除学生信息函数
{
	cout << "请输入你要删除学生信息的学号: ";
	int type = 1;
	bool exist = searchByNo(type);
	if (!exist){
		cout << "无该学生的信息,请核对你输入的学号!!" << endl;
		goOn();
	}
	else {
		save();
		cout << "删除完成" << endl;
		goOn();
	}
}

string  Administrator::getNoTmp(){
	return this->noTmp;
}

void Administrator::goOn(){
	cout << endl << "请按任意键继续..." << endl;
	cin.get();
	cin.get();
}

bool Administrator::judgeNo(string no){
	if (no >= "00000001"&&no <= "99999999"){
		return true;
	}
	return false;
}

void Administrator::menu()
{
	while (true) {
		welcome();
		std::cout << "  ╭--------------------------------------╮" << endl;
		std::cout << " │          1 录入学生信息:               │" << endl;
		std::cout << " │          2 修改学生信息:               │" << endl;
		std::cout << " │          3 删除学生信息:               │" << endl;
		std::cout << " │          4 显示全部学生信息:           │" << endl;
		std::cout << " │          5 查找学生信息:               │" << endl;
		std::cout << " │          6 退出管理员登录:             │" << endl;
		std::cout << " ╰----------------------------------------╯" << endl;
		output << "请输入:    ";
		char choose;
		std::cin >> choose;
		switch (choose)
		{
		case '1': add(); break;
		case '2': modify(ADMINISTRATOR_MODIFY); break;
		case '3': delete_(); break;
		case '4': showAllStudentInformation(SHOW_ALL_STUDENT_INFORMATION); break;
		case '5': search(); break;
		case '6': return;
		default:
		{
				   std::cout << "请按规定输入选择项!" << endl;
				   Sleep(1500);
				   menu();
		}
		}
	}
}

void Administrator::modify(int type)                 //修改学生信息函数
{
	if (ADMINISTRATOR_MODIFY == type){
		//只能按学号修改
		cout << "请输入你要修改学生信息的学号: ";
		int type = 3;
		bool exist = searchByNo(ADMINISTRATOR_MODIFY);
		if (!exist){
			cout << "无该学生的信息,请核对你输入的学号!!" << endl;
			goOn();
		}
		else {
			save();
			cout << "修改完成" << endl;
			goOn();
		}
	}
}

void Administrator::read()                       //读取学生信息函数
{
	Student *p = new Student();
	ifstream is("Student.txt", ios::in);
	if (!is)//如果打开文件失败
	{
		ofstream os("Student.txt", ios::out);
		os.close();
		return;
	}
	this->student.clear();//将之前的链表清空,然后将文件中的信息全都保存到list中
	while (!is.eof()){
		if (p->readFileOfStudent(is)){
			this->student.push_back(*p);
		}		
	}
	is.close();
}
void Administrator::save()                                 //保存学生信息函数
{
	ofstream of("Student.txt", ios::out);
	list<Student>::iterator begin, end, i;
	begin = student.begin();
	end = student.end();
	for (i = begin; i != end; i++)
	{
		i->writeFileOfStudent(of);//将学生信息写入到文件
	}
	of.close();
}
void Administrator::search()
{
	cout << "请输入你要搜索的学生信息的学号: ";
	bool exist = false;
	exist = searchByNo(4);
	if (!exist){
		cout << "无该学生的信息,请核对你输入的学号!!" << endl;
		goOn();
	}
	else {
		showLine();
		cout << "查找完成!" << endl;
		save();
		goOn();
	}
}
bool Administrator::searchByNo(int type){
	string noTmp;
	cin >> noTmp;
	if (!judgeNo(noTmp)){
		cout << "你输入的学号非法,请确认后再输入!" << endl;
		while (true)
		{
			output << "请输入学号:";
			cin >> noTmp;
			if (!judgeNo(noTmp)){
				cout << "你输入的学号非法,请确认后再输入!" << endl;
			}
			else {
				break;
			}
		}
	}

	this->noTmp = noTmp;
	this->read();
	list<Student>::iterator begin, end, i;
	begin = student.begin();
	end = student.end();
	bool existStudent = false;
	for (i = begin; i != end; i++)
	{
		if (i->getNo() == noTmp) {//如果学号存在
			switch (type){
			case 1:
				this->student.erase(i);
				return true;
			case 2:
				//search success when add()
				return true;
			case 3:
				i->updateStudentInformation(type, noTmp);
				return true;
			case 4:
				i->showSingleStudentInformation();
				return true;
			case 6:
				i->updateStudentInformation(type, noTmp);
				return true;
			}
		}
	}
	return false;
}
void Administrator::showAllStudentInformation(int user)
{
	this->read();
	list<Student>::iterator begin, end, i;
	begin = student.begin();
	end = student.end();
	if (STUDENT_MODIFY == user) {
		for (i = begin; i != end; i++)
		{
			if (i->getNo() == this->getNoTmp()){
				i->updateStudentInformation(3, this->getNoTmp());
				this->save();
				return;//修改完保存直接退出
			}
		}
	}
	else {
		//if (ADMINISTRATOR_MODIFY==)
	}
	cout << resetiosflags(ios::left);
	if (!student.empty()){
		showLine();
		std::cout
			<< cr << "学号│"
			<< cr << "姓名│" 
			<< cr << "年龄│"
			<< cr << "性别│"
			<< cr << "宿舍地址│"
			<< cr << "计算机│"
			<< cr << "数学│"
			<< cr << "英语│" << endl;
		if (1 == user){//如果是管理员用户
			for (i = begin; i != end; i++)
			{
				i->showSingleStudentInformation();
			}
			showLine();
			cout << "提示:所有的信息显示完成!!" << endl;
		}
		if (2 == user) {//如果是学生用户
			for (i = begin; i != end; i++)
			{
				if (i->getNo() == this->getNoTmp()){
					i->showSingleStudentInformation();
				}
			}
			showLine();
		}
		goOn();
	}
}
inline  void Administrator::showLine(){
	std::cout << "-----------------------------------------------------------------------------------------------" << endl;
}
void Administrator::validate() {
	string username, password;
	output << "请输入管理员用户名:";
	std::cin >> username;
	string usernamestring;
	ifstream ipasswordFile;
	ipasswordFile.open(".\\account.txt", ios::in | ios::app);
	if (!ipasswordFile.is_open())
	{
		fstream ipasswordFile(".\\account.txt", ios::in | ios::app);
		ipasswordFile.close();
		return;
	}
	ipasswordFile >> usernamestring;
	if (username != usernamestring){
		std::cout << "用户名错误!" << endl;
		Sleep(2500);
		return;
	}
	else {
		output << "请输入管理员密码:";
		std::cin >> password;
		string passwordstring;
		ipasswordFile >> passwordstring;
		ipasswordFile >> passwordstring;
		if (password != passwordstring){
			std::cout << "密码错误" << endl;
			Sleep(2500);
			return;
		}
		else {
			this->menu();//如果验证成功
		}
	}
}