#ifndef GRADUATEMANAGE_H//刘继元
#define GRADUATEMANAGE_H
#include"Graduate.h"
#include"Menu.h"
#include"Manage.h"
#include"Date.h"
#include<vector>
class GraduateManage:public Manage{
private:
	vector<Graduate*> graVec;
	Menu menu;
	Date date;
public:
	vector<Graduate*> getGraduates(){return graVec;}
	 void add();//增加
	 void addMany();//写入
	 void searchById();//查找
	 void deleteById();//删除
	 void print(int i) ;//打印
	 void searchByName();
	 void changeInfo();//修改
	 void manage();//管理研究生各个功能
};
#endif
