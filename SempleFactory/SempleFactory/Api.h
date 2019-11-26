#ifndef __API_HPP__
#define __API_HPP__
#include <stdio.h>
#include <string>

//�����ӿڵ���
class Api
{
public:
	virtual void test(std::string str) = 0;
};

//ʵ���߼����� one �������ӿ�
class ImplOne : public Api
{
public:
	void test(std::string str)
	{
		printf("this is ImplOne,str %s\n", str.c_str());
	}
};

//ʵ���߼����� two �������ӿ�
class ImplTwo : public Api
{
public:
	void test(std::string str)
	{
		printf("this is ImplTwo,str %s\n", str.c_str());
	}
};

#endif