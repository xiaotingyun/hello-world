#ifndef TEACHERMANAGE_H//王福瑞
#define TEACHERMANAGE_H
#include"Teacher.h"
#include"Menu.h"
#include"Manage.h"
#include"Date.h"
#include<vector>
class TeacherManage:public Manage{
private:
	vector<Teacher*> teaVec;
	Menu menu;
	Date date;
public:
	vector<Teacher*> getTeachers(){return teaVec;}
	 void add();//增加
	 void addMany();//写入
	 void searchById();//查找
	 void deleteById();//删除
	 void print(int i) ;//打印
	 void searchByName();
	 void changeInfo();//修改
	 void manage();//管理教师各个功能

};
#endif
