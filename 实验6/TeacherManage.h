#ifndef TEACHERMANAGE_H//������
#define TEACHERMANAGE_H
#include"Teacher.h"
#include"Menu.h"
#include"Manage.h"
#include"Date.h"
#include<vector>
class TeacherManage:public Manage{
private:
	vector<Teacher*> teaVec;
	Menu menu;
	Date date;
public:
	vector<Teacher*> getTeachers(){return teaVec;}
	 void add();//����
	 void addMany();//д��
	 void searchById();//����
	 void deleteById();//ɾ��
	 void print(int i) ;//��ӡ
	 void searchByName();
	 void changeInfo();//�޸�
	 void manage();//�����ʦ��������

};
#endif
