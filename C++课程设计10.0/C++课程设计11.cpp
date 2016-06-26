#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <string>
#include "Student.h"
#include "Administrator.h"
#define output (cout <<setiosflags(ios::left)<<setfill(' ')<<setw(20))
using namespace std;

int selectLoginUser();
void studentLogin();
void administratorLogin();
extern void welcome();


int main()
{
	int flag = 0;
	while (true) {
		flag=selectLoginUser();//选择登录模式
		switch (flag) {
		case 1:
			studentLogin();//学生登录
			break;
		case 2:
			administratorLogin();//管理员登录
			break;
		case 3:
			exit(0);
		}
	}
	return 0;
}
void studentLogin(){
	Student student;
	student.validate();//if not exist,return false
	return;
}
int selectLoginUser(){
	int flag = 0;
	welcome();
	std::cout << "  ╭--------------------------------------╮" << endl;
	std::cout << " │          1 学生登录                   │" << endl;
	std::cout << " │          2 管理员登录                 │" << endl;
	std::cout << " │          3 退出                       │" << endl;
	std::cout << "  -----------------------------------------" << endl;
	output << "请输入:   ";
	char choose;
	std::cin >> choose;
	if (std::cin.good()) {
		switch (choose)
		{
		case '1':
			flag = 1;
			break;
		case '2':
			flag = 2;
			break;
		case '3':
			flag = 3;
			break;
		default:
		{
				   std::cout << "请按规定输入选择项!" << endl;
				   Sleep(1500);
				   selectLoginUser();
		}
		}
	}
	else {
		std::cin.clear();
		selectLoginUser();
	}
	return flag;
}
void welcome(){//欢迎界面
	system("color A0");
	time_t t;
	time(&t);
	system("cls");

	std::cout << "   ";
	for (int i = 0; i <= 60; i++) {
		std::cout << char(6);
	}
	std::cout << endl;
	std::cout << "		欢迎登陆学生信息管理系统                    " << endl << endl;

	std::cout << "     \t  当前时间: " << ctime(&t) << "" << endl;
	std::cout << "     \t  作者:梁仲海 郭浩东" << endl;
	for (int i = 0; i <= 60; i++) {
		std::cout << char(6);
	}
	std::cout << endl;
	std::cout << "请按键选择操作（选择数字序号）" << endl;
	std::cout << "\n";
}

void administratorLogin(){
	Administrator administrator;
	administrator.validate();//管理员登录验证
}