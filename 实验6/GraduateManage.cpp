#include"GraduateManage.h"//刘继元
using namespace std;
void  GraduateManage::print(int i) 
{
	cout<<"姓名:"<<graVec.at(i)->getName();
	cout<<"\t身份证:"<<graVec.at(i)->getId();
	cout<<"\t年龄:"<<graVec.at(i)->getAge();
	cout<<"\t研究方向:"<<graVec.at(i)->getDirection();
	cout<<endl;	
}
void GraduateManage::deleteById()
{
	int flag=0;
	string pid;
	if(graVec.size()>0)
	{
		cout<<"请输入要删除研究生的身份证"<<endl;
		cin>>pid;
		vector<Graduate*>::iterator i;
		for(i=graVec.begin();i!=graVec.end();)
		{
			if(pid==(*i)->getId()){
				delete *i;//释放该地址上的值（该值是第i个Student对象的地址）
				i=graVec.erase(i);//从容器里删除i的地址，并返回i的地址
				cout<<"删除成功"<<endl;
				flag=1;
				break;
			}else 
				i++;
		}
	}
	else
	{
		cout<<"没有研究生可以删除"<<endl;
		flag=1;
	}
	if(flag==0)
	{
		cout<<"该研究生不存在"<<endl;
	}	
}
void GraduateManage::searchById()
{
	string id;
	cout<<"请输入身份证:";
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
		cout<<"身份证为"<<id<<"的研究生不存在!!";
	}
}
void GraduateManage::searchByName()
{
	string name;
	cout<<"请输入姓名:";
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
		cout<<"姓名为"<<name<<"的研究生不存在!!";
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
	cout<<"请输入姓名，身份证，研究方向(年龄由身份证算出)"<<endl;
	cin>>tempname>>tempid>>tempdirection;
	for(int i=0;i<18;i++)
	{pid[i]=tempid[i]-'0';}
	year=pid[6]*1000+pid[7]*100+pid[8]*10+pid[9];
	month=pid[10]*10+pid[11];  //根据身份证号得出出生年、月
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
		cout<<"是否继续输入(y/n)"<<endl;
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
	cout<<"请输入要修改研究生的姓名:";
	cin>>name;
	int flag=0;
	for(int i=0;i<graVec.size();i++)
	{
		if(name==graVec.at(i)->getName()){
			 print(i);
			 cout<<"请选择要修改的信息"<<endl;
			 cout<<"1.姓名"<<endl;
			 cout<<"2.身份证"<<endl;
			 cout<<"3.年龄"<<endl;
			 cout<<"4.研究方向"<<endl;
			 cout<<"5.所有信息"<<endl;
			 cin>>m;
			 switch(m)
			 {
			 case '1':cout<<"请输入新姓名"<<endl;
				 cin>>tempname;
				 graVec.at(i)->setName(tempname);
				 break;
			 case '2':cout<<"请输入新身份证"<<endl;
				 cin>>tempid;
				 graVec.at(i)->setId(tempid);
				break;
			 case '3':cout<<"请输入新年龄"<<endl;
				 cin>>tempage;
				 graVec.at(i)->setAge(tempage);
				 break;
			 case '4':cout<<"请输入新研究方向"<<endl;
				 cin>>tempreseacher;
				 graVec.at(i)->setDirection(tempreseacher);
				break;
			 case '5':cout<<"请输入新姓名，身份证，年龄，研究方向"<<endl;
				 cin>>tempname>>tempid>>tempage>>tempreseacher;
				 graVec.at(i)->setName(tempname);
				 graVec.at(i)->setId(tempid);
				 graVec.at(i)->setAge(tempage);
				 graVec.at(i)->setDirection(tempreseacher);
				 break;
			 default:
				 system("cls");
				cout<<"此选项不存在,请重新输入"<<endl;
				 cin.clear();
				 cin.sync();
				 break;
			 }
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"姓名为"<<name<<"的教师不存在!!";
	}
}
void GraduateManage::manage()//熊鑫鑫
{
	char m;
	string pMenu[]={"1.输入研究生信息","2.增加信息","3.按学号查找","4.按姓名查找","5.删除信息","6.修改信息","7.查看所有信息","0.退出"};
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
			cout<<"输入错误，请重新输入"<<endl;
			cin.clear();
			cin.sync();
				system("pause");
			
		}

	}
}