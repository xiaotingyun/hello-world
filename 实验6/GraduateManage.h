#ifndef GRADUATEMANAGE_H//����Ԫ
#define GRADUATEMANAGE_H
#include"Graduate.h"
#include"Menu.h"
#include"Manage.h"
#include"Date.h"
#include<vector>
class GraduateManage:public Manage{
private:
	vector<Graduate*> graVec;
	Menu menu;
	Date date;
public:
	vector<Graduate*> getGraduates(){return graVec;}
	 void add();//����
	 void addMany();//д��
	 void searchById();//����
	 void deleteById();//ɾ��
	 void print(int i) ;//��ӡ
	 void searchByName();
	 void changeInfo();//�޸�
	 void manage();//�����о�����������
};
#endif
