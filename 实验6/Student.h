#ifndef STUDENT_H//�ϳ�Բ
#define STUDENT_H
#include"People.h"
#include<iostream>
#include<string>
using namespace std;
class Student:public People{
private:
	string grade;
public:
	void setName(string pname){name=pname;}//��ֵ
	void setId(string pid){id=pid;}
	void setAge(const int page){age=page;}
	void setGrade(string pgrade){grade=pgrade;}
	string getName(){return name;}//����ֵ
	string getId(){return id;}
	int getAge()const{return age;}
	string getGrade(){return grade;}

};
#endif