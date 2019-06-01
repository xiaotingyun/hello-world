#include"TeacherManage.h"//������
using namespace std;
void  TeacherManage::print(int i) 
{
	cout<<"����:"<<teaVec.at(i)->getName();
	cout<<"\t���֤:"<<teaVec.at(i)->getId();
	cout<<"\t����:"<<teaVec.at(i)->getAge();
	cout<<"\tְ��:"<<teaVec.at(i)->getJob();
	cout<<endl;	
}
void TeacherManage::deleteById()
{
	int flag=0;
	string pid;
	if(teaVec.size()>0)
	{
		cout<<"������Ҫɾ����ʦ�����֤"<<endl;
		cin>>pid;
		vector<Teacher*>::iterator i;
		for(i=teaVec.begin();i!=teaVec.end();)
		{
			if(pid==(*i)->getId()){
				delete *i;//�ͷŸõ�ַ�ϵ�ֵ����ֵ�ǵ�i��Student����ĵ�ַ��
				i=teaVec.erase(i);//��������ɾ��i�ĵ�ַ��������i�ĵ�ַ
				cout<<"ɾ���ɹ�"<<endl;
				flag=1;
				break;
			}else 
				i++;
		}
	}
	else
	{
		cout<<"û�н�ʦ����ɾ��"<<endl;
		flag=1;
	}
	if(flag==0)
	{
		cout<<"�ý�ʦ������"<<endl;
	}	
}
void TeacherManage::searchById()
{
	string id;
	cout<<"���������֤:";
	cin>>id;
	int flag=0;
	for(int i=0;i<teaVec.size();i++)
	{
		if(id==teaVec.at(i)->getId()){
			 print(i);	
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"���֤Ϊ"<<id<<"�Ľ�ʦ������!!";
	}
}
void TeacherManage::searchByName()
{
	string name;
	cout<<"����������:";
	cin>>name;
	int flag=0;
	for(int i=0;i<teaVec.size();i++)
	{
		if(name==teaVec.at(i)->getName()){
			 print(i);	
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"����Ϊ"<<name<<"�Ľ�ʦ��������!!";
	}
}
void TeacherManage::add(){
	string tempname;
	string tempid;
	int pid[18];
	int tempage;
	string tempjob;
	int year;
	int month;
	Teacher* temptea=new Teacher();
	date.setDate(2019,6);
	cout<<"���������������֤��ְ��(���������֤���)"<<endl;
	cin>>tempname>>tempid>>tempjob;
	for(int i=0;i<18;i++)
	{pid[i]=tempid[i]-'0';}
	year=pid[6]*1000+pid[7]*100+pid[8]*10+pid[9];
	month=pid[10]*10+pid[11];  //�������֤�ŵó������ꡢ��
	tempage=date.calculate(year,month);
	temptea->setName(tempname);
	temptea->setId(tempid);
	temptea->setAge(tempage);
	temptea->setJob(tempjob);
	teaVec.push_back(temptea);
}
void TeacherManage::addMany()
{
	char i;
	do{
		add();
		cout<<"�Ƿ��������(y/n)"<<endl;
		cin>>i;
	}while(i=='y'||i=='Y');
}
void TeacherManage::changeInfo()
{
	char m;
	string tempname;
	string tempid;
	int tempage;
	string tempjob;
	string name;
	cout<<"������Ҫ�޸Ľ�ʦ������:";
	cin>>name;
	int flag=0;
	for(int i=0;i<teaVec.size();i++)
	{
		if(name==teaVec.at(i)->getName()){
			 print(i);
			 cout<<"��ѡ��Ҫ�޸ĵ���Ϣ"<<endl;
			 cout<<"1.����"<<endl;
			 cout<<"2.���֤"<<endl;
			 cout<<"3.����"<<endl;
			 cout<<"4.ְ��"<<endl;
			 cout<<"5.������Ϣ"<<endl;
			 cin>>m;
			 switch(m)
			 {
			 case '1':cout<<"������������"<<endl;
				 cin>>tempname;
				 teaVec.at(i)->setName(tempname);
				 break;
			 case '2':cout<<"�����������֤"<<endl;
				 cin>>tempid;
				 teaVec.at(i)->setId(tempid);
				break;
			 case '3':cout<<"������������"<<endl;
				 cin>>tempage;
				 teaVec.at(i)->setAge(tempage);
				 break;
			 case '4':cout<<"��������ְ��"<<endl;
				 cin>>tempjob;
				 teaVec.at(i)->setJob(tempjob);
				break;
			 case '5':cout<<"�����������������֤�����䣬ְ��"<<endl;
				 cin>>tempname>>tempid>>tempage>>tempjob;
				 teaVec.at(i)->setName(tempname);
				 teaVec.at(i)->setId(tempid);
				 teaVec.at(i)->setAge(tempage);
				 teaVec.at(i)->setJob(tempjob);
				 break;
			 default:cout<<"��ѡ�����,����������"<<endl;
			 }
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"����Ϊ"<<name<<"�Ľ�ʦ������!!";
	}
}
void TeacherManage::manage()
{
	char m;
	string pMenu[]={"1.�����ʦ��Ϣ","2.������Ϣ","3.�����֤����","4.����������","5.ɾ����Ϣ","6.�޸���Ϣ","7.�鿴������Ϣ","0.�˳�"};
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
				for(int i=0;i<teaVec.size();i++)
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
				break;
			
		}

	}
}