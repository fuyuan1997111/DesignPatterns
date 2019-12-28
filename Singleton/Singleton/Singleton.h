/*
����ģʽ (Singleton)
ȫ�ֽ�����һ��ʵ��
*/
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <mutex>

template <typename T>
class Singleton
{
public:
	/* ��ȡʵ�� */
	static T* Instance()
	{
		static std::mutex _mutex;
		if (!m_instance)
		{
			/* ���� ��ֹ���̴߳������ʵ�� */
			std::lock_guard<std::mutex> _lock(_mutex);
			if (!m_instance)
			{
				m_instance = new T();
				static SingletonClose _close;
			}
		}
		return m_instance;
	}

private:
	static T* m_instance;		//��¼����ָ��

	/* �ڴ��ͷź��� */
	class SingletonClose
	{
	public:
		~SingletonClose()
		{
			if (Singleton<T>::m_instance)
			{
				delete Singleton<T>::m_instance;
				Singleton<T>::m_instance = nullptr;
			}
		}
	};
	/* end �ڴ��ͷź��� */

};
/* ��������ʼ������ */
template <typename T>
T* Singleton<T>::m_instance = nullptr;

#endif