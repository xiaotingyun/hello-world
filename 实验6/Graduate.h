#ifndef GRADUATE_H//������
#define GRADUATE_H
#include"People.h"
#include<iostream>
#include<string>
using namespace std;
class Graduate:public People{
private:
	string direction;
public:
	void setName(string pname){name=pname;}//��ֵ
	void setId(string pid){id=pid;}
	void setAge(const int page){age=page;}
	void setDirection(string pdirection){direction=pdirection;}
	string getName(){return name;}//����ֵ
	string getId(){return id;}
	int getAge()const{return age;}
	string getDirection(){return direction;}


};
#endif