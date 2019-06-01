#ifndef  _LOGINUSER_H//熊鑫鑫
#define  _LOGINUSER_H
#include <iostream>
#include <stdlib.h>                              //使用system函数；
#include <string>
#include <cstdio>
#include <Windows.h>                           //使用Sleep函数；
#include <conio.h>                              //使用_getch()函数；
#include <fstream>                               //即可读又可写；
using namespace std;
class User {
public:
	void setWindow();
	void setPro();
	void menu();                                           //菜单；
	void regest();                                       //注册；
	void login();                                       //登入；
protected:
	char username[10], password[10];
};
#endif
