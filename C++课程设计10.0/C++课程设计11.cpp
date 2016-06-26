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
		flag=selectLoginUser();//ѡ���¼ģʽ
		switch (flag) {
		case 1:
			studentLogin();//ѧ����¼
			break;
		case 2:
			administratorLogin();//����Ա��¼
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
	std::cout << "  �q--------------------------------------�r" << endl;
	std::cout << " ��          1 ѧ����¼                   ��" << endl;
	std::cout << " ��          2 ����Ա��¼                 ��" << endl;
	std::cout << " ��          3 �˳�                       ��" << endl;
	std::cout << "  -----------------------------------------" << endl;
	output << "������:   ";
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
				   std::cout << "�밴�涨����ѡ����!" << endl;
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
void welcome(){//��ӭ����
	system("color A0");
	time_t t;
	time(&t);
	system("cls");

	std::cout << "   ";
	for (int i = 0; i <= 60; i++) {
		std::cout << char(6);
	}
	std::cout << endl;
	std::cout << "		��ӭ��½ѧ����Ϣ����ϵͳ                    " << endl << endl;

	std::cout << "     \t  ��ǰʱ��: " << ctime(&t) << "" << endl;
	std::cout << "     \t  ����:���ٺ� ���ƶ�" << endl;
	for (int i = 0; i <= 60; i++) {
		std::cout << char(6);
	}
	std::cout << endl;
	std::cout << "�밴��ѡ�������ѡ��������ţ�" << endl;
	std::cout << "\n";
}

void administratorLogin(){
	Administrator administrator;
	administrator.validate();//����Ա��¼��֤
}