
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include"Student.h"
#include<list>
class Administrator  :public Login                           //功能类
{
public:
	Administrator();                            //构造函数
	~Administrator();//析构函数
	static inline void showLine();				//表格线
	void validate();						//登录验证
	void menu();                          //菜单函数
	void add();                           //录入学生信息函数
	void modify(int);						  //修改学生信息函数
	void delete_();                         //删除学生信息函数
	void showAllStudentInformation(int );                           //显示学生信息函数
	void search();                        //查询学生信息函数
	bool searchByNo(int);				//按学号查找学生
	string getNoTmp();
	void setNoTmp(string);
	void goOn();
private:
	string noTmp;
	list<Student>student;				//学生信息,使用"链表"
	void read();                           //从文件中读取学生信息函数
	void save();                           //将学生信息函数保存到文件中
	bool judgeNo(string);							//判断学号是否输入合法
};
#endif