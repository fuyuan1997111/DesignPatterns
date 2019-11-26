#ifndef __SEMPLE_FACTORY_HPP__
#define __SEMPLE_FACTORY_HPP__
/*
简单工厂	Semple Factory

对类进行封装，把调用者安排的明明白白！

此项目，安排调用者调用 ImplOne 或 ImplTwo 任意一个类
*/

#include "Api.h"
#include <map>
typedef void* (*Constructor)();		//防函数 用来记录 类创建函数


//用来记录 类创建函数
class CObjectFactory
{
public:
	static void registerClass(std::string className, Constructor constructor)
	{
		//通过函数名，注册函数
		constructors()[className] = constructor;
	}

	static void* createClass(std::string className)
	{
		Constructor _constructor = nullptr;
		
		//查询 是否存在当前函数
		if (constructors().find(className) != constructors().end())
			_constructor = constructors().find(className)->second;
		
		if (nullptr == _constructor)return nullptr;

		//返回 类创建函数
		return _constructor();
	}


private:
	inline static std::map<std::string, Constructor>& constructors()
	{
		//创建一个静态 红黑树，记录 类创建函数
		static std::map<std::string, Constructor> _instance;
		return _instance;
	}
};


//工厂类
class Factory
{
	public:
		static Api* createApi()
		{
			Api* _api = nullptr;
			//获取创建函数
			//可根据需求 通过配置 或 其他防止改变 创建函数
			_api = static_cast<Api*>(CObjectFactory::createClass("ImplOne"));
			//_api = static_cast<Api*>(CObjectFactory::createClass("ImplTwo"));
			return _api;
		}
};



//宏原型
//class ImplOneHelper
//{
//public:
//	ImplOneHelper()
//	{
//		//注册创建函数
//		CObjectFactory::registerClass("ImplOne", ImplOneHelper::createrObjectFunc);
//	}
//
//	//创建函数
//	static void* createrObjectFunc()
//	{
//		return new ImplOne;
//	}
//};


//注册指定 类的 创建函数
#define REG_CLASS(class_name) \
class class_name##Helper\
{\
public:\
	class_name##Helper()\
	{\
		CObjectFactory::registerClass(#class_name, class_name##Helper::createrObjectFunc);\
	}\
	static void* createrObjectFunc()\
	{\
		return new class_name##;\
	}\
};\
class_name##Helper class_name##helper;

#endif