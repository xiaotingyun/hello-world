#include"StudentManage.h"//�ϳ�Բ
using namespace std;
void  StudentManage::print(int i) 
{
	cout<<"����:"<<stuVec.at(i)->getName();
	cout<<"\tѧ��:"<<stuVec.at(i)->getId();
	cout<<"\t����:"<<stuVec.at(i)->getAge();
	cout<<"\t�༶:"<<stuVec.at(i)->getGrade();
	cout<<endl;	
}
void StudentManage::deleteById()
{
	int flag=0;
	string pid;
	if(stuVec.size()>0)
	{
		cout<<"������Ҫɾ��ѧ����ѧ��"<<endl;
		cin>>pid;
		vector<Student*>::iterator i;
		for(i=stuVec.begin();i!=stuVec.end();)
		{
			if(pid==(*i)->getId()){
				delete *i;//�ͷŸõ�ַ�ϵ�ֵ����ֵ�ǵ�i��Student����ĵ�ַ��
				i=stuVec.erase(i);//��������ɾ��i�ĵ�ַ��������i�ĵ�ַ,����i++
				cout<<"ɾ���ɹ�"<<endl;
				flag=1;
				break;
			}else 
				i++;
		}
	}
	else
	{
		cout<<"û��ѧ������ɾ��"<<endl;
		flag=1;
	}
	if(flag==0)
	{
		cout<<"��ѧ�Ų�����"<<endl;
	}	
}
void StudentManage::searchById()
{
	string id;
	cout<<"������ѧ��:";
	cin>>id;
	int flag=0;
	for(int i=0;i<stuVec.size();i++)
	{
		if(id==stuVec.at(i)->getId()){
			 print(i);	
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"ѧ��Ϊ"<<id<<"��ѧ��������!!";
	}
}
void StudentManage::searchByName()
{
	string name;
	cout<<"����������:";
	cin>>name;
	int flag=0;
	for(int i=0;i<stuVec.size();i++)
	{
		if(name==stuVec.at(i)->getName()){
			 print(i);	
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"����Ϊ"<<name<<"��ѧ��������!!";
	}
}
void StudentManage::changeInfo()
{
	char m;
	string tempname;
	string tempid;
	int tempage;
	string tempgrade;
	string id;	
	cout<<"������Ҫ�޸�ѧ����ѧ��:";
	cin>>id;
	int flag=0;
	for(int i=0;i<stuVec.size();i++)
	{
		if(id==stuVec.at(i)->getId()){
			 print(i);
			 cout<<"��ѡ��Ҫ�޸ĵ���Ϣ"<<endl;
			 cout<<"1.����"<<endl;
			 cout<<"2.ѧ��"<<endl;
			 cout<<"3.����"<<endl;
			 cout<<"4.�༶"<<endl;
			 cout<<"5.������Ϣ"<<endl;
			 cin>>m;
			 switch(m)
			 {
			 case '1':cout<<"������������"<<endl;
				 cin>>tempname;
				 stuVec.at(i)->setName(tempname);
				 break;
			 case '2':cout<<"��������ѧ��"<<endl;
				 cin>>tempid;
				 stuVec.at(i)->setId(tempid);
				break;
			 case '3':cout<<"������������"<<endl;
				 cin>>tempage;
				 stuVec.at(i)->setAge(tempage);
				 break;
			 case '4':cout<<"�������°༶"<<endl;
				 cin>>tempgrade;
				 stuVec.at(i)->setGrade(tempgrade);
				break;
			 case '5':cout<<"��������������ѧ�ţ����䣬�༶"<<endl;
				 cin>>tempname>>tempid>>tempage>>tempgrade;
				 stuVec.at(i)->setName(tempname);
				 stuVec.at(i)->setId(tempid);
				 stuVec.at(i)->setAge(tempage);
				 stuVec.at(i)->setGrade(tempgrade);
				 break;
			 default:cout<<"��ѡ�����,����������"<<endl;
				 cin.clear();
				 cin.sync();
				 break;
			 }
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"ѧ��Ϊ"<<id<<"��ѧ��������!!";
	}
}
void StudentManage::add(){
	string tempname;
	string tempid;
	int tempage;
	string tempgrade;
	Student* tempstu=new Student();
	cout<<"������������ѧ�ţ����䣬�༶"<<endl;
	cin>>tempname>>tempid>>tempage>>tempgrade;
	tempstu->setName(tempname);
	tempstu->setId(tempid);
	tempstu->setAge(tempage);
	tempstu->setGrade(tempgrade);
	stuVec.push_back(tempstu);
}
void StudentManage::addMany()
{
	char i;
	do{
		add();
		cout<<"�Ƿ��������(y/n)"<<endl;
		cin>>i;
	}while(i=='y'||i=='Y');
}
void StudentManage::manage()
{
	char m;
	string pMenu[]={"1.����ѧ����Ϣ","2.������Ϣ","3.��ѧ�Ų���","4.����������","5.ɾ����Ϣ","6.�޸���Ϣ","7.�鿴������Ϣ","0.�˳�"};
	menu.setMenu(pMenu,8);
	while(1)
	{
		menu.printMenu();
		cout<<"��ѡ����"<<endl;
		m=menu.getChioce();
		if(m=='0')
			break;
		switch(m)
		{
		case '1':system("cls");
				addMany();
				system("pause");
				break;
		case '2':system("cls");
				add();
				system("pause");
				break;
		case '3':system("cls");
				searchById();
				system("pause");
				break;
		case '4':system("cls");
				searchByName();
				system("pause");
				break;
		case '5':system("cls");
				deleteById();
				system("pause");
				break;
		case '6':system("cls");		
				changeInfo();
				system("pause");
				break;
		case '7':
			{
				system("cls");
				for(int i=0;i<stuVec.size();i++)
				{
					print(i);
				}
				system("pause");
				break;
			}
		default:system("cls");
			cout<<"�����������������"<<endl;
			cin.clear();
			cin.sync();
				system("pause");
			
		}

	}
}