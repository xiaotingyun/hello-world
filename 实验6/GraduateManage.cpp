#include"GraduateManage.h"//����Ԫ
using namespace std;
void  GraduateManage::print(int i) 
{
	cout<<"����:"<<graVec.at(i)->getName();
	cout<<"\t���֤:"<<graVec.at(i)->getId();
	cout<<"\t����:"<<graVec.at(i)->getAge();
	cout<<"\t�о�����:"<<graVec.at(i)->getDirection();
	cout<<endl;	
}
void GraduateManage::deleteById()
{
	int flag=0;
	string pid;
	if(graVec.size()>0)
	{
		cout<<"������Ҫɾ���о��������֤"<<endl;
		cin>>pid;
		vector<Graduate*>::iterator i;
		for(i=graVec.begin();i!=graVec.end();)
		{
			if(pid==(*i)->getId()){
				delete *i;//�ͷŸõ�ַ�ϵ�ֵ����ֵ�ǵ�i��Student����ĵ�ַ��
				i=graVec.erase(i);//��������ɾ��i�ĵ�ַ��������i�ĵ�ַ
				cout<<"ɾ���ɹ�"<<endl;
				flag=1;
				break;
			}else 
				i++;
		}
	}
	else
	{
		cout<<"û���о�������ɾ��"<<endl;
		flag=1;
	}
	if(flag==0)
	{
		cout<<"���о���������"<<endl;
	}	
}
void GraduateManage::searchById()
{
	string id;
	cout<<"���������֤:";
	cin>>id;
	int flag=0;
	for(int i=0;i<graVec.size();i++)
	{
		if(id==graVec.at(i)->getId()){
			 print(i);	
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"���֤Ϊ"<<id<<"���о���������!!";
	}
}
void GraduateManage::searchByName()
{
	string name;
	cout<<"����������:";
	cin>>name;
	int flag=0;
	for(int i=0;i<graVec.size();i++)
	{
		if(name==graVec.at(i)->getName()){
			 print(i);	
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"����Ϊ"<<name<<"���о���������!!";
	}
}
void GraduateManage::add(){
	string tempname;
	string tempid;
	int pid[18];
	int tempage;
	string tempdirection;
	int year;
	int month;
	Graduate* temptea=new Graduate();
	date.setDate(2019,6);
	cout<<"���������������֤���о�����(���������֤���)"<<endl;
	cin>>tempname>>tempid>>tempdirection;
	for(int i=0;i<18;i++)
	{pid[i]=tempid[i]-'0';}
	year=pid[6]*1000+pid[7]*100+pid[8]*10+pid[9];
	month=pid[10]*10+pid[11];  //�������֤�ŵó������ꡢ��
	tempage=date.calculate(year,month);
	temptea->setName(tempname);
	temptea->setId(tempid);
	temptea->setAge(tempage);
	temptea->setDirection(tempdirection);
	graVec.push_back(temptea);
}
void GraduateManage::addMany()
{
	char i;
	do{
		add();
		cout<<"�Ƿ��������(y/n)"<<endl;
		cin>>i;
	}while(i=='y'||i=='Y');
}
void GraduateManage::changeInfo()
{
	char m;
	string tempname;
	string tempid;
	int tempage;
	string tempreseacher;
	string name;
	cout<<"������Ҫ�޸��о���������:";
	cin>>name;
	int flag=0;
	for(int i=0;i<graVec.size();i++)
	{
		if(name==graVec.at(i)->getName()){
			 print(i);
			 cout<<"��ѡ��Ҫ�޸ĵ���Ϣ"<<endl;
			 cout<<"1.����"<<endl;
			 cout<<"2.���֤"<<endl;
			 cout<<"3.����"<<endl;
			 cout<<"4.�о�����"<<endl;
			 cout<<"5.������Ϣ"<<endl;
			 cin>>m;
			 switch(m)
			 {
			 case '1':cout<<"������������"<<endl;
				 cin>>tempname;
				 graVec.at(i)->setName(tempname);
				 break;
			 case '2':cout<<"�����������֤"<<endl;
				 cin>>tempid;
				 graVec.at(i)->setId(tempid);
				break;
			 case '3':cout<<"������������"<<endl;
				 cin>>tempage;
				 graVec.at(i)->setAge(tempage);
				 break;
			 case '4':cout<<"���������о�����"<<endl;
				 cin>>tempreseacher;
				 graVec.at(i)->setDirection(tempreseacher);
				break;
			 case '5':cout<<"�����������������֤�����䣬�о�����"<<endl;
				 cin>>tempname>>tempid>>tempage>>tempreseacher;
				 graVec.at(i)->setName(tempname);
				 graVec.at(i)->setId(tempid);
				 graVec.at(i)->setAge(tempage);
				 graVec.at(i)->setDirection(tempreseacher);
				 break;
			 default:
				 system("cls");
				cout<<"��ѡ�����,����������"<<endl;
				 cin.clear();
				 cin.sync();
				 break;
			 }
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"����Ϊ"<<name<<"�Ľ�ʦ������!!";
	}
}
void GraduateManage::manage()//������
{
	char m;
	string pMenu[]={"1.�����о�����Ϣ","2.������Ϣ","3.��ѧ�Ų���","4.����������","5.ɾ����Ϣ","6.�޸���Ϣ","7.�鿴������Ϣ","0.�˳�"};
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
		case '7':
			{
				system("cls");
				for(int i=0;i<graVec.size();i++)
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