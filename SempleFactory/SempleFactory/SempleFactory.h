#ifndef __SEMPLE_FACTORY_HPP__
#define __SEMPLE_FACTORY_HPP__
/*
�򵥹���	Semple Factory

������з�װ���ѵ����߰��ŵ������װף�

����Ŀ�����ŵ����ߵ��� ImplOne �� ImplTwo ����һ����
*/

#include "Api.h"
#include <map>
typedef void* (*Constructor)();		//������ ������¼ �ഴ������


//������¼ �ഴ������
class CObjectFactory
{
public:
	static void registerClass(std::string className, Constructor constructor)
	{
		//ͨ����������ע�ắ��
		constructors()[className] = constructor;
	}

	static void* createClass(std::string className)
	{
		Constructor _constructor = nullptr;
		
		//��ѯ �Ƿ���ڵ�ǰ����
		if (constructors().find(className) != constructors().end())
			_constructor = constructors().find(className)->second;
		
		if (nullptr == _constructor)return nullptr;

		//���� �ഴ������
		return _constructor();
	}


private:
	inline static std::map<std::string, Constructor>& constructors()
	{
		//����һ����̬ ���������¼ �ഴ������
		static std::map<std::string, Constructor> _instance;
		return _instance;
	}
};


//������
class Factory
{
	public:
		static Api* createApi()
		{
			Api* _api = nullptr;
			//��ȡ��������
			//�ɸ������� ͨ������ �� ������ֹ�ı� ��������
			_api = static_cast<Api*>(CObjectFactory::createClass("ImplOne"));
			//_api = static_cast<Api*>(CObjectFactory::createClass("ImplTwo"));
			return _api;
		}
};



//��ԭ��
//class ImplOneHelper
//{
//public:
//	ImplOneHelper()
//	{
//		//ע�ᴴ������
//		CObjectFactory::registerClass("ImplOne", ImplOneHelper::createrObjectFunc);
//	}
//
//	//��������
//	static void* createrObjectFunc()
//	{
//		return new ImplOne;
//	}
//};


//ע��ָ�� ��� ��������
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