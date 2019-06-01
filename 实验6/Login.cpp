#include <iostream>//熊鑫鑫
#include "Login.h"
using namespace std;
void User::setWindow() {                              //主界面的设置函数；
	system("title 大学信息管理系统");
	system("color f0");
	system("mode con cols=50 lines=12");
}
void User::setPro() {                                     //进度条显示函数；
	string str("**");
	for (int i = 0; i <= 10; i++) {
		system("cls");
		cout << str << endl;
		cout << i * 10 << "%" << endl;
		str += "**";
		Sleep(50);                              //使程序暂停500ms；
	}
}
void User::menu() {
	cout << "\t欢迎来到大学信息管理系统7.0" << endl;
	cout << "1.我是新用户" << endl;
	cout << "2.我已注册过" << endl;                 //菜单函数；
}
void User::regest() {
	fstream filename;
	string username;
	string password;
	filename.open("userAccount.txt");
	cout << "请输入你要注册的账号：";
	cin >> username;
	filename << username << endl;
	cout << "请输入你要注册的密码：";
	cin >> password;
	filename << password << endl;
	filename.close();
	cout << "注册成功" << endl;
}
void User::login() {
	int flag = 0;
	do {
		cout << "\t欢迎来到登录界面" << endl;
		string username;
		string password;
		cout << "账号：";
		cin >> username;
		cout << "密码：";
		cin >> password;
		fstream filename;
		filename.open("userAccount.txt");
		if (!filename.is_open())
			cout << "打开失败"<<endl;
		string temp[10];
		int i = 0;
		while (!filename.eof()) {
			while (!filename.eof()) {                                  // 若未到文件结束一直循环  
				getline(filename, temp[i], '\n');                      //读取一行，以换行符结束，存入 temp[] 中
				i++;                                                   //下一行
			}
		}
		
		if (temp[0] == username && temp[1] == password) {
			flag = 1;
		}
		filename.close();
		if (flag != 1) {
			cout << "账号或密码输入错误，请重新输入！"<<endl;
		}
	} while (flag != 1);
}
