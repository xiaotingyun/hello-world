#include"Menu.h"
#include"StudentManage.h"
#include"TeacherManage.h"
#include"GraduateManage.h"
#include"Login.h"
void mainMenu();
void Login();
int main()
{
	Login();//����
	mainMenu();//���˵�
	return 0;
}
void mainMenu()//����Ԫ
{	
	Manage* manage[3];//��������ָ��
	manage[0]=new StudentManage;
	manage[1]=new TeacherManage;
	manage[2]=new GraduateManage;
	char m;
	while(1)
	{
		cout<<"1.ѧ������"<<endl;
		cout<<"2.��ʦ����"<<endl;
		cout<<"3.�о�������"<<endl;
		cout<<"4.����"<<endl;
		cout<<"0.�˳�"<<endl;
		cout<<"��ѡ����"<<endl;
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
			cout<<"ѧУ����ϵͳ2.0"<<endl;
			cout<<"���ʱ��:5.29"<<endl;
			cout<<"�鳤��������8003118010"<<endl;
			cout<<"����Ԫ��8003118008"<<endl;
			cout<<"������8003118009"<<endl;
			cout<<"�ϳ�Բ��8003118002"<<endl;
			system("pause");
			break;
		default:system("cls");
			cin.clear();
			cin.sync();
			cout<<"�����������������"<<endl;
				system("pause");	
				break;
		}
	}//end while
}
void Login()//������
{
	User *admin;
	admin = new User;
	admin->setWindow();
	int flag=-1;
	do
	{	
		admin->menu();
		char op;
		cout << "���������ѡ��" << endl;
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
			cout<<"�������"<<endl;
			cin.clear();//��ֹ�������ַ���������뻺����
			cin.sync();
			flag=1;
			break;
		}
	}while(flag==1);
	system("mode con cols=100 lines=24");
	admin->setPro();
}

