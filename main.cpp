#include <iostream>
#include "ThreadManager.h"

using namespace std;

int main()
{
	cout<<"This is simple thread application"<<endl;
	ThreadManager tm;
	tm.threadLoncher("My name is Udara Abeyrathne");

	return 0;
}