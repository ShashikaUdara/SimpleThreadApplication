#include "ThreadManager.h"

void ThreadManager :: threadLoncher(string something)
{
	pthread_t thread_item[THREAD_NUM];
	int i;

	string temp, buff_route;

	for(i=0; i<THREAD_NUM; i++)
	{
		stringstream temp_sstr;
		temp = "";
		temp_sstr << i;
		temp_sstr >> temp;
		cout<<i<<"_"<<temp<<endl;
		buff_route = something + "_" + temp;

		if(pthread_create(&thread_item[i], NULL, sampleThreadFunction, static_cast<void*>(&buff_route)))
		{
			cout<<"Can't create thread"<<endl;
			exit(-1);
		}

		// wait for targetted thread termination
		if(pthread_join(thread_item[i], NULL))
		{
			cout<<"The thread "<<pthread_self()<<" can't be terminated"<< endl;
			exit(-2);
		}
		else
		{
			cout<<"Thread "<<pthread_self()<<" terminated"<<endl;
		}
	}

	pthread_exit(NULL);
}

void* ThreadManager :: sampleThreadFunction(void* something)
{
	string &temp_buff = *(static_cast<string*>(something));
	cout<<"This is the passed string: "<<temp_buff<<endl;
	pthread_exit(NULL);
}