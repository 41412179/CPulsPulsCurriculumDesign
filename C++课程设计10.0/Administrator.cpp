
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

void Administrator::add()                           //¼��ѧ����Ϣ����
{
	string chooseyes;
	int choose;
	system("cls");
	do{
		std::cout << "��������Ҫ��ӵ�ѧ����Ϣ:" << endl;
		output << "������ѧ��: ";
		bool exist = false;
		exist = searchByNo(EXITST_NO);//2��ʾadd(),����Ѿ����ڸ���žͷ���true
		//s����ѧ��
		if (!exist){
			int type = 3;
			Student *p = new Student();
			p->updateStudentInformation(type, this->getNoTmp());//������ӵ�ѧ����Ϣ
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
		else {//�����ѧ������
			cout << "��ѧ���Ѵ��ڣ���˶���Ϣ���������!\n\n";
			std::cout << "1.�������˵�\n2.������� ------- ";
			std::cin >> choose;
			while (choose != 1 && choose != 2)
			{
				std::cout << "1.�������˵�\n2.������� ------- ";
				std::cin >> choose;
			}
			if (choose == 1)
				menu();
			else if (choose == 2)
				add();
		}
		int flag = 0;
		while (true){
			std::cout << "�Ƿ����������Ϣ?(Y\\N) ------- ";
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
					cout << "�����������!!!" << endl;
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

void Administrator::delete_()           //ɾ��ѧ����Ϣ����
{
	cout << "��������Ҫɾ��ѧ����Ϣ��ѧ��: ";
	int type = 1;
	bool exist = searchByNo(type);
	if (!exist){
		cout << "�޸�ѧ������Ϣ,��˶��������ѧ��!!" << endl;
		goOn();
	}
	else {
		save();
		cout << "ɾ�����" << endl;
		goOn();
	}
}

string  Administrator::getNoTmp(){
	return this->noTmp;
}

void Administrator::goOn(){
	cout << endl << "�밴���������..." << endl;
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
		std::cout << "  �q--------------------------------------�r" << endl;
		std::cout << " ��          1 ¼��ѧ����Ϣ:               ��" << endl;
		std::cout << " ��          2 �޸�ѧ����Ϣ:               ��" << endl;
		std::cout << " ��          3 ɾ��ѧ����Ϣ:               ��" << endl;
		std::cout << " ��          4 ��ʾȫ��ѧ����Ϣ:           ��" << endl;
		std::cout << " ��          5 ����ѧ����Ϣ:               ��" << endl;
		std::cout << " ��          6 �˳�����Ա��¼:             ��" << endl;
		std::cout << " �t----------------------------------------�s" << endl;
		output << "������:    ";
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
				   std::cout << "�밴�涨����ѡ����!" << endl;
				   Sleep(1500);
				   menu();
		}
		}
	}
}

void Administrator::modify(int type)                 //�޸�ѧ����Ϣ����
{
	if (ADMINISTRATOR_MODIFY == type){
		//ֻ�ܰ�ѧ���޸�
		cout << "��������Ҫ�޸�ѧ����Ϣ��ѧ��: ";
		int type = 3;
		bool exist = searchByNo(ADMINISTRATOR_MODIFY);
		if (!exist){
			cout << "�޸�ѧ������Ϣ,��˶��������ѧ��!!" << endl;
			goOn();
		}
		else {
			save();
			cout << "�޸����" << endl;
			goOn();
		}
	}
}

void Administrator::read()                       //��ȡѧ����Ϣ����
{
	Student *p = new Student();
	ifstream is("Student.txt", ios::in);
	if (!is)//������ļ�ʧ��
	{
		ofstream os("Student.txt", ios::out);
		os.close();
		return;
	}
	this->student.clear();//��֮ǰ���������,Ȼ���ļ��е���Ϣȫ�����浽list��
	while (!is.eof()){
		if (p->readFileOfStudent(is)){
			this->student.push_back(*p);
		}		
	}
	is.close();
}
void Administrator::save()                                 //����ѧ����Ϣ����
{
	ofstream of("Student.txt", ios::out);
	list<Student>::iterator begin, end, i;
	begin = student.begin();
	end = student.end();
	for (i = begin; i != end; i++)
	{
		i->writeFileOfStudent(of);//��ѧ����Ϣд�뵽�ļ�
	}
	of.close();
}
void Administrator::search()
{
	cout << "��������Ҫ������ѧ����Ϣ��ѧ��: ";
	bool exist = false;
	exist = searchByNo(4);
	if (!exist){
		cout << "�޸�ѧ������Ϣ,��˶��������ѧ��!!" << endl;
		goOn();
	}
	else {
		showLine();
		cout << "�������!" << endl;
		save();
		goOn();
	}
}
bool Administrator::searchByNo(int type){
	string noTmp;
	cin >> noTmp;
	if (!judgeNo(noTmp)){
		cout << "�������ѧ�ŷǷ�,��ȷ�Ϻ�������!" << endl;
		while (true)
		{
			output << "������ѧ��:";
			cin >> noTmp;
			if (!judgeNo(noTmp)){
				cout << "�������ѧ�ŷǷ�,��ȷ�Ϻ�������!" << endl;
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
		if (i->getNo() == noTmp) {//���ѧ�Ŵ���
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
				return;//�޸��걣��ֱ���˳�
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
			<< cr << "ѧ�ũ�"
			<< cr << "������" 
			<< cr << "���䩦"
			<< cr << "�Ա�"
			<< cr << "�����ַ��"
			<< cr << "�������"
			<< cr << "��ѧ��"
			<< cr << "Ӣ�辶" << endl;
		if (1 == user){//����ǹ���Ա�û�
			for (i = begin; i != end; i++)
			{
				i->showSingleStudentInformation();
			}
			showLine();
			cout << "��ʾ:���е���Ϣ��ʾ���!!" << endl;
		}
		if (2 == user) {//�����ѧ���û�
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
	output << "���������Ա�û���:";
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
		std::cout << "�û�������!" << endl;
		Sleep(2500);
		return;
	}
	else {
		output << "���������Ա����:";
		std::cin >> password;
		string passwordstring;
		ipasswordFile >> passwordstring;
		ipasswordFile >> passwordstring;
		if (password != passwordstring){
			std::cout << "�������" << endl;
			Sleep(2500);
			return;
		}
		else {
			this->menu();//�����֤�ɹ�
		}
	}
}