#include"Menu.h"
#include"StudentManage.h"
#include"TeacherManage.h"
#include"GraduateManage.h"
#include"Login.h"
void mainMenu();
void Login();
int main()
{
	Login();//登入
	mainMenu();//主菜单
	return 0;
}
void mainMenu()//刘继元
{	
	Manage* manage[3];//三个基类指针
	manage[0]=new StudentManage;
	manage[1]=new TeacherManage;
	manage[2]=new GraduateManage;
	char m;
	while(1)
	{
		cout<<"1.学生管理"<<endl;
		cout<<"2.教师管理"<<endl;
		cout<<"3.研究生管理"<<endl;
		cout<<"4.关于"<<endl;
		cout<<"0.退出"<<endl;
		cout<<"请选择功能"<<endl;
		cin>>m;
		if(m=='0')
			break;
		switch(m)
		{
		case '1':system("cls");
				manage[0]->manage();
				system("pause");
				break;
		case '2':system("cls");
				manage[1]->manage();
				system("pause");
				break;
		case '3':system("cls");
				manage[2]->manage();
				system("pause");
				break;
		case '4':system("cls");
			cout<<"学校管理系统2.0"<<endl;
			cout<<"完成时间:5.29"<<endl;
			cout<<"组长：熊鑫鑫8003118010"<<endl;
			cout<<"刘继元：8003118008"<<endl;
			cout<<"王福瑞：8003118009"<<endl;
			cout<<"邢朝圆：8003118002"<<endl;
			system("pause");
			break;
		default:system("cls");
			cin.clear();
			cin.sync();
			cout<<"输入错误，请重新输入"<<endl;
				system("pause");	
				break;
		}
	}//end while
}
void Login()//熊鑫鑫
{
	User *admin;
	admin = new User;
	admin->setWindow();
	int flag=-1;
	do
	{	
		admin->menu();
		char op;
		cout << "请输入你的选择：" << endl;
		cin >> op;
		switch (op) {
		case '1':
			admin->regest();
			Sleep(500);
			system("cls");
			admin->login();
			break;
		case '2':
			admin->login();
			break;
		default:
			system("cls");
			cout<<"输入错误"<<endl;
			cin.clear();//防止输入多个字符，清空输入缓冲区
			cin.sync();
			flag=1;
			break;
		}
	}while(flag==1);
	system("mode con cols=100 lines=24");
	admin->setPro();
}

