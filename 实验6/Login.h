#ifndef  _LOGINUSER_H//������
#define  _LOGINUSER_H
#include <iostream>
#include <stdlib.h>                              //ʹ��system������
#include <string>
#include <cstdio>
#include <Windows.h>                           //ʹ��Sleep������
#include <conio.h>                              //ʹ��_getch()������
#include <fstream>                               //���ɶ��ֿ�д��
using namespace std;
class User {
public:
	void setWindow();
	void setPro();
	void menu();                                           //�˵���
	void regest();                                       //ע�᣻
	void login();                                       //���룻
protected:
	char username[10], password[10];
};
#endif
