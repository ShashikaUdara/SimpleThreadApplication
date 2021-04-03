#ifndef THREAD_MANAGER_H
#define THREAD_MANAGER_H

#include <iostream>
#include <pthread.h>
#include <sstream>

#define THREAD_NUM 10

using namespace std;

class ThreadManager
{
	public:
		ThreadManager() {}
		~ThreadManager() {}
		void threadLoncher(string something);
		static void* sampleThreadFunction(void* something);
};

#endif