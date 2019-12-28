#include <stdio.h>
#include "Singleton.h"

//使用例子
//1.单例对象
class SingleObject : public Singleton<SingleObject>
{
public:
	void SetNumber(const int val) { m_number = val; }
	int GetNumber() { return m_number; }

private:
	friend Singleton<SingleObject>;		//设置友元函数 使 Singleton 可以访问私有函数
	SingleObject() {}					//私有化构造函数 禁止外部构造此函数

	//测试变量
	int m_number = 0;
};

//2.可单、可多对象
class Object : public Singleton<Object>
{
public:
	void SetNumber(const int val) { m_number = val; }
	int GetNumber() { return m_number; }

private:
	//测试变量
	int m_number = 0;
};



int main()
{
	//单例对象
	//SingleObject _test;		//报错
	SingleObject *_pobject = SingleObject::Instance();
	_pobject->SetNumber(10);
	SingleObject *_pobject2 = SingleObject::Instance();
	_pobject2->SetNumber(20);
	printf("Single object object2 [%d,%d]\n",
		_pobject->GetNumber(),
		_pobject2->GetNumber());


	//Object 略...
	return 0;
}