#ifndef TEACHER_H//王福瑞
#define TEACHER_H
#include"People.h"
#include<iostream>
#include<string>
using namespace std;
class Teacher:public People{
private:
	string job;
public:
	void setName(string pname){name=pname;}//设值
	void setId(string pid){id=pid;}
	void setAge(const int page){age=page;}
	void setJob(string pjob){job=pjob;}
	string getName(){return name;}//返回值
	string getId(){return id;}
	int getAge()const{return age;}
	string getJob(){return job;}
};
#endif