#ifndef MENU_H//����Ԫ
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
	   void setMenu(string pmenu[],int size);//���ò˵�
	   string* getMenu(){return menu;}//���ز˵�
	   void printMenu();//��ӡ�˵�
		char getChioce();//ѡ����
		void Initialization();//��ʼ��
};
#endif