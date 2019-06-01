#ifndef STUDENTMANAGE_H//邢朝圆
#define STUDENTMANAGE_H
#include"Student.h"
#include"Menu.h"
#include"Manage.h"
#include<vector>
class StudentManage:public Manage{
private:
	vector<Student*> stuVec;
	Menu menu;
public:
	vector<Student*> getStudents(){return stuVec;}
	 void add();//增加
	 void addMany();//写入
	 void searchById();//查找
	 void deleteById();//删除
	 void print(int i) ;//打印
	 void searchByName();
	 void changeInfo();//修改信息
	 void manage();//管理学生各个功能
};
#endif
