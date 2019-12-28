#include <stdio.h>
#include "Singleton.h"

//ʹ������
//1.��������
class SingleObject : public Singleton<SingleObject>
{
public:
	void SetNumber(const int val) { m_number = val; }
	int GetNumber() { return m_number; }

private:
	friend Singleton<SingleObject>;		//������Ԫ���� ʹ Singleton ���Է���˽�к���
	SingleObject() {}					//˽�л����캯�� ��ֹ�ⲿ����˺���

	//���Ա���
	int m_number = 0;
};

//2.�ɵ����ɶ����
class Object : public Singleton<Object>
{
public:
	void SetNumber(const int val) { m_number = val; }
	int GetNumber() { return m_number; }

private:
	//���Ա���
	int m_number = 0;
};



int main()
{
	//��������
	//SingleObject _test;		//����
	SingleObject *_pobject = SingleObject::Instance();
	_pobject->SetNumber(10);
	SingleObject *_pobject2 = SingleObject::Instance();
	_pobject2->SetNumber(20);
	printf("Single object object2 [%d,%d]\n",
		_pobject->GetNumber(),
		_pobject2->GetNumber());

	//Object ��...

	return 0;
}