#ifndef GRADUATE_H//熊鑫鑫
#define GRADUATE_H
#include"People.h"
#include<iostream>
#include<string>
using namespace std;
class Graduate:public People{
private:
	string direction;
public:
	void setName(string pname){name=pname;}//设值
	void setId(string pid){id=pid;}
	void setAge(const int page){age=page;}
	void setDirection(string pdirection){direction=pdirection;}
	string getName(){return name;}//返回值
	string getId(){return id;}
	int getAge()const{return age;}
	string getDirection(){return direction;}


};
#endif