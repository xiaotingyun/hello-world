#ifndef MANAGE_H//������
#define MANAGE_H
class Manage{//����������Ļ���
public:
	virtual void add()=0;//����
	virtual void addMany()=0;//д��
	virtual void searchById()=0;//����
	virtual void deleteById()=0;//ɾ��
	virtual void print(int i)=0 ;//��ӡ
	virtual void searchByName()=0;
	virtual void changeInfo()=0;//�޸�
	virtual void manage()=0;//����ѧ����������
};
#endif
