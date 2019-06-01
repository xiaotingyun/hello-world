#ifndef MANAGE_H//王福瑞
#define MANAGE_H
class Manage{//各个管理类的基类
public:
	virtual void add()=0;//增加
	virtual void addMany()=0;//写入
	virtual void searchById()=0;//查找
	virtual void deleteById()=0;//删除
	virtual void print(int i)=0 ;//打印
	virtual void searchByName()=0;
	virtual void changeInfo()=0;//修改
	virtual void manage()=0;//管理学生各个功能
};
#endif
