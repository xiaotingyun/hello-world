#include <iostream>//������
#include "Login.h"
using namespace std;
void User::setWindow() {                              //����������ú�����
	system("title ��ѧ��Ϣ����ϵͳ");
	system("color f0");
	system("mode con cols=50 lines=12");
}
void User::setPro() {                                     //��������ʾ������
	string str("**");
	for (int i = 0; i <= 10; i++) {
		system("cls");
		cout << str << endl;
		cout << i * 10 << "%" << endl;
		str += "**";
		Sleep(50);                              //ʹ������ͣ500ms��
	}
}
void User::menu() {
	cout << "\t��ӭ������ѧ��Ϣ����ϵͳ7.0" << endl;
	cout << "1.�������û�" << endl;
	cout << "2.����ע���" << endl;                 //�˵�������
}
void User::regest() {
	fstream filename;
	string username;
	string password;
	filename.open("userAccount.txt");
	cout << "��������Ҫע����˺ţ�";
	cin >> username;
	filename << username << endl;
	cout << "��������Ҫע������룺";
	cin >> password;
	filename << password << endl;
	filename.close();
	cout << "ע��ɹ�" << endl;
}
void User::login() {
	int flag = 0;
	do {
		cout << "\t��ӭ������¼����" << endl;
		string username;
		string password;
		cout << "�˺ţ�";
		cin >> username;
		cout << "���룺";
		cin >> password;
		fstream filename;
		filename.open("userAccount.txt");
		if (!filename.is_open())
			cout << "��ʧ��"<<endl;
		string temp[10];
		int i = 0;
		while (!filename.eof()) {
			while (!filename.eof()) {                                  // ��δ���ļ�����һֱѭ��  
				getline(filename, temp[i], '\n');                      //��ȡһ�У��Ի��з����������� temp[] ��
				i++;                                                   //��һ��
			}
		}
		
		if (temp[0] == username && temp[1] == password) {
			flag = 1;
		}
		filename.close();
		if (flag != 1) {
			cout << "�˺Ż���������������������룡"<<endl;
		}
	} while (flag != 1);
}
