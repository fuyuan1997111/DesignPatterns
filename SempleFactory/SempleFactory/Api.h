#ifndef __API_HPP__
#define __API_HPP__
#include <stdio.h>
#include <string>

//公开接口的类
class Api
{
public:
	virtual void test(std::string str) = 0;
};

//实现逻辑的类 one 不公开接口
class ImplOne : public Api
{
public:
	void test(std::string str)
	{
		printf("this is ImplOne,str %s\n", str.c_str());
	}
};

//实现逻辑的类 two 不公开接口
class ImplTwo : public Api
{
public:
	void test(std::string str)
	{
		printf("this is ImplTwo,str %s\n", str.c_str());
	}
};

#endif