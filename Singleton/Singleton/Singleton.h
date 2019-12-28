/*
单例模式 (Singleton)
全局仅创建一个实例
*/
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <mutex>

template <typename T>
class Singleton
{
public:
	/* 获取实例 */
	static T* Instance()
	{
		static std::mutex _mutex;
		if (!m_instance)
		{
			/* 加锁 防止多线程创建多个实例 */
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
	static T* m_instance;		//记录对象指针

	/* 内存释放函数 */
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
	/* end 内存释放函数 */

};
/* 声明并初始化变量 */
template <typename T>
T* Singleton<T>::m_instance = nullptr;

#endif