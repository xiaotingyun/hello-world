#include"Menu.h"//����Ԫ
Menu::Menu(string pmenu[],int size)
{
	Initialization();
	for(int i=0;i<size;i++)
	{
		menu[i]=pmenu[i];
	}
}
void Menu::Initialization()
{
	for(int i=0;i<N;i++)
	{
		menu[i]="0";
	}
}
void Menu::setMenu(string pmenu[],int size)
{
	int length=size;
	Initialization();
	if(length>N)
	{
		cout<<"���õĹ��������ڹ涨����Ŀ��ֻȡǰ10��"<<endl;
		length=N;
	} 	
	for(int i=0;i<length;i++)
	{
		menu[i]=pmenu[i];
	}
}
void Menu::printMenu()
{
	for(int i=0;i<10;i++)
	{
		if(menu[i]!="0")
		cout<<menu[i]<<endl;
	}
}
char Menu::getChioce()
{
	char index;
	cin>>index;
	return index;
}
