#ifndef TEACHER_H//������
#define TEACHER_H
#include"People.h"
#include<iostream>
#include<string>
using namespace std;
class Teacher:public People{
private:
	string job;
public:
	void setName(string pname){name=pname;}//��ֵ
	void setId(string pid){id=pid;}
	void setAge(const int page){age=page;}
	void setJob(string pjob){job=pjob;}
	string getName(){return name;}//����ֵ
	string getId(){return id;}
	int getAge()const{return age;}
	string getJob(){return job;}
};
#endif