#ifndef STUDENTMANAGE_H//�ϳ�Բ
#define STUDENTMANAGE_H
#include"Student.h"
#include"Menu.h"
#include"Manage.h"
#include<vector>
class StudentManage:public Manage{
private:
	vector<Student*> stuVec;
	Menu menu;
public:
	vector<Student*> getStudents(){return stuVec;}
	 void add();//����
	 void addMany();//д��
	 void searchById();//����
	 void deleteById();//ɾ��
	 void print(int i) ;//��ӡ
	 void searchByName();
	 void changeInfo();//�޸���Ϣ
	 void manage();//����ѧ����������
};
#endif
