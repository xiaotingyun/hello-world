#ifndef MENU_H//刘继元
#define MENU_H
#include<iostream>
#include<string>
const int N=10;
using namespace std;
class Menu
{
private:string menu[N];
public:Menu(){}
	   Menu(string pmenu[],int size);
	   void setMenu(string pmenu[],int size);//设置菜单
	   string* getMenu(){return menu;}//返回菜单
	   void printMenu();//打印菜单
		char getChioce();//选择功能
		void Initialization();//初始化
};
#endif