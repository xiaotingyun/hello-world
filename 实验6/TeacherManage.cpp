#include"TeacherManage.h"//王福瑞
using namespace std;
void  TeacherManage::print(int i) 
{
	cout<<"姓名:"<<teaVec.at(i)->getName();
	cout<<"\t身份证:"<<teaVec.at(i)->getId();
	cout<<"\t年龄:"<<teaVec.at(i)->getAge();
	cout<<"\t职称:"<<teaVec.at(i)->getJob();
	cout<<endl;	
}
void TeacherManage::deleteById()
{
	int flag=0;
	string pid;
	if(teaVec.size()>0)
	{
		cout<<"请输入要删除教师的身份证"<<endl;
		cin>>pid;
		vector<Teacher*>::iterator i;
		for(i=teaVec.begin();i!=teaVec.end();)
		{
			if(pid==(*i)->getId()){
				delete *i;//释放该地址上的值（该值是第i个Student对象的地址）
				i=teaVec.erase(i);//从容器里删除i的地址，并返回i的地址
				cout<<"删除成功"<<endl;
				flag=1;
				break;
			}else 
				i++;
		}
	}
	else
	{
		cout<<"没有教师可以删除"<<endl;
		flag=1;
	}
	if(flag==0)
	{
		cout<<"该教师不存在"<<endl;
	}	
}
void TeacherManage::searchById()
{
	string id;
	cout<<"请输入身份证:";
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
		cout<<"身份证为"<<id<<"的教师不存在!!";
	}
}
void TeacherManage::searchByName()
{
	string name;
	cout<<"请输入姓名:";
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
		cout<<"姓名为"<<name<<"的教师生不存在!!";
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
	cout<<"请输入姓名，身份证，职称(年龄由身份证算出)"<<endl;
	cin>>tempname>>tempid>>tempjob;
	for(int i=0;i<18;i++)
	{pid[i]=tempid[i]-'0';}
	year=pid[6]*1000+pid[7]*100+pid[8]*10+pid[9];
	month=pid[10]*10+pid[11];  //根据身份证号得出出生年、月
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
		cout<<"是否继续输入(y/n)"<<endl;
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
	cout<<"请输入要修改教师的姓名:";
	cin>>name;
	int flag=0;
	for(int i=0;i<teaVec.size();i++)
	{
		if(name==teaVec.at(i)->getName()){
			 print(i);
			 cout<<"请选择要修改的信息"<<endl;
			 cout<<"1.姓名"<<endl;
			 cout<<"2.身份证"<<endl;
			 cout<<"3.年龄"<<endl;
			 cout<<"4.职称"<<endl;
			 cout<<"5.所有信息"<<endl;
			 cin>>m;
			 switch(m)
			 {
			 case '1':cout<<"请输入新姓名"<<endl;
				 cin>>tempname;
				 teaVec.at(i)->setName(tempname);
				 break;
			 case '2':cout<<"请输入新身份证"<<endl;
				 cin>>tempid;
				 teaVec.at(i)->setId(tempid);
				break;
			 case '3':cout<<"请输入新年龄"<<endl;
				 cin>>tempage;
				 teaVec.at(i)->setAge(tempage);
				 break;
			 case '4':cout<<"请输入新职称"<<endl;
				 cin>>tempjob;
				 teaVec.at(i)->setJob(tempjob);
				break;
			 case '5':cout<<"请输入新姓名，身份证，年龄，职称"<<endl;
				 cin>>tempname>>tempid>>tempage>>tempjob;
				 teaVec.at(i)->setName(tempname);
				 teaVec.at(i)->setId(tempid);
				 teaVec.at(i)->setAge(tempage);
				 teaVec.at(i)->setJob(tempjob);
				 break;
			 default:cout<<"此选项不存在,请重新输入"<<endl;
			 }
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"姓名为"<<name<<"的教师不存在!!";
	}
}
void TeacherManage::manage()
{
	char m;
	string pMenu[]={"1.输入教师信息","2.增加信息","3.按身份证查找","4.按姓名查找","5.删除信息","6.修改信息","7.查看所有信息","0.退出"};
	menu.setMenu(pMenu,8);
	while(1)
	{
		menu.printMenu();
		cout<<"请选择功能"<<endl;
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
			cout<<"输入错误，请重新输入"<<endl;
			cin.clear();
			cin.sync();
				system("pause");
				break;
			
		}

	}
}