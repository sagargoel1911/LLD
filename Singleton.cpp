#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
	Singleton() {}
	Singleton(Singleton &) {}
	Singleton operator=(Singleton &) {}
	static Singleton *instance;
	static mutex mtx;

public:
	static Singleton *getInstance()
	{
		if (instance == nullptr)
		{
			mtx.lock();
			if (instance == nullptr)
			{
				instance = new Singleton();
			}
			mtx.unlock();
		}
		return instance;
	}
};

int main()
{
	return 0;
}