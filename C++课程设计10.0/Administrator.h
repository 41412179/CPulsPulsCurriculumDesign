
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include"Student.h"
#include<list>
class Administrator  :public Login                           //������
{
public:
	Administrator();                            //���캯��
	~Administrator();//��������
	static inline void showLine();				//�����
	void validate();						//��¼��֤
	void menu();                          //�˵�����
	void add();                           //¼��ѧ����Ϣ����
	void modify(int);						  //�޸�ѧ����Ϣ����
	void delete_();                         //ɾ��ѧ����Ϣ����
	void showAllStudentInformation(int );                           //��ʾѧ����Ϣ����
	void search();                        //��ѯѧ����Ϣ����
	bool searchByNo(int);				//��ѧ�Ų���ѧ��
	string getNoTmp();
	void setNoTmp(string);
	void goOn();
private:
	string noTmp;
	list<Student>student;				//ѧ����Ϣ,ʹ��"����"
	void read();                           //���ļ��ж�ȡѧ����Ϣ����
	void save();                           //��ѧ����Ϣ�������浽�ļ���
	bool judgeNo(string);							//�ж�ѧ���Ƿ�����Ϸ�
};
#endif