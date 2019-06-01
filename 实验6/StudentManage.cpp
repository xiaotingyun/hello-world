#include"StudentManage.h"//邢朝圆
using namespace std;
void  StudentManage::print(int i) 
{
	cout<<"姓名:"<<stuVec.at(i)->getName();
	cout<<"\t学号:"<<stuVec.at(i)->getId();
	cout<<"\t年龄:"<<stuVec.at(i)->getAge();
	cout<<"\t班级:"<<stuVec.at(i)->getGrade();
	cout<<endl;	
}
void StudentManage::deleteById()
{
	int flag=0;
	string pid;
	if(stuVec.size()>0)
	{
		cout<<"请输入要删除学生的学号"<<endl;
		cin>>pid;
		vector<Student*>::iterator i;
		for(i=stuVec.begin();i!=stuVec.end();)
		{
			if(pid==(*i)->getId()){
				delete *i;//释放该地址上的值（该值是第i个Student对象的地址）
				i=stuVec.erase(i);//从容器里删除i的地址，并返回i的地址,并且i++
				cout<<"删除成功"<<endl;
				flag=1;
				break;
			}else 
				i++;
		}
	}
	else
	{
		cout<<"没有学生可以删除"<<endl;
		flag=1;
	}
	if(flag==0)
	{
		cout<<"该学号不存在"<<endl;
	}	
}
void StudentManage::searchById()
{
	string id;
	cout<<"请输入学号:";
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
		cout<<"学号为"<<id<<"的学生不存在!!";
	}
}
void StudentManage::searchByName()
{
	string name;
	cout<<"请输入姓名:";
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
		cout<<"姓名为"<<name<<"的学生不存在!!";
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
	cout<<"请输入要修改学生的学号:";
	cin>>id;
	int flag=0;
	for(int i=0;i<stuVec.size();i++)
	{
		if(id==stuVec.at(i)->getId()){
			 print(i);
			 cout<<"请选择要修改的信息"<<endl;
			 cout<<"1.姓名"<<endl;
			 cout<<"2.学号"<<endl;
			 cout<<"3.年龄"<<endl;
			 cout<<"4.班级"<<endl;
			 cout<<"5.所有信息"<<endl;
			 cin>>m;
			 switch(m)
			 {
			 case '1':cout<<"请输入新姓名"<<endl;
				 cin>>tempname;
				 stuVec.at(i)->setName(tempname);
				 break;
			 case '2':cout<<"请输入新学号"<<endl;
				 cin>>tempid;
				 stuVec.at(i)->setId(tempid);
				break;
			 case '3':cout<<"请输入新年龄"<<endl;
				 cin>>tempage;
				 stuVec.at(i)->setAge(tempage);
				 break;
			 case '4':cout<<"请输入新班级"<<endl;
				 cin>>tempgrade;
				 stuVec.at(i)->setGrade(tempgrade);
				break;
			 case '5':cout<<"请输入新姓名，学号，年龄，班级"<<endl;
				 cin>>tempname>>tempid>>tempage>>tempgrade;
				 stuVec.at(i)->setName(tempname);
				 stuVec.at(i)->setId(tempid);
				 stuVec.at(i)->setAge(tempage);
				 stuVec.at(i)->setGrade(tempgrade);
				 break;
			 default:cout<<"此选项不存在,请重新输入"<<endl;
				 cin.clear();
				 cin.sync();
				 break;
			 }
			flag=1;
			break;
		}	
	}
	if(flag==0){
		cout<<"学号为"<<id<<"的学生不存在!!";
	}
}
void StudentManage::add(){
	string tempname;
	string tempid;
	int tempage;
	string tempgrade;
	Student* tempstu=new Student();
	cout<<"请输入姓名，学号，年龄，班级"<<endl;
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
		cout<<"是否继续输入(y/n)"<<endl;
		cin>>i;
	}while(i=='y'||i=='Y');
}
void StudentManage::manage()
{
	char m;
	string pMenu[]={"1.输入学生信息","2.增加信息","3.按学号查找","4.按姓名查找","5.删除信息","6.修改信息","7.查看所有信息","0.退出"};
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
				for(int i=0;i<stuVec.size();i++)
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