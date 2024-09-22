#include <iostream>
#include <set>
using namespace std;

class ObserverInterface
{
public:
	virtual ~ObserverInterface() {};
	virtual void onNotify(string msg) = 0;
};

class ConcreteObserver : public ObserverInterface
{
	int userId;

public:
	ConcreteObserver(int id)
	{
		this->userId = id;
	}
	void onNotify(string message)
	{
		cout << "Observer notified " << userId << " message: " << message << endl;
	}
};

class Group
{
public:
	set<ObserverInterface *> observerList;
	void subscribe(ObserverInterface *user)
	{
		observerList.insert(user);
	}
	void unsubscribe(ObserverInterface *user)
	{
		observerList.erase(user);
	}
	void notify(string msg)
	{
		for (auto user : observerList)
		{
			user->onNotify(msg);
		}
	}
};

int main()
{
	Group *group = new Group();
	ConcreteObserver *user1 = new ConcreteObserver(1);
	ConcreteObserver *user2 = new ConcreteObserver(2);
	ConcreteObserver *user3 = new ConcreteObserver(3);

	group->subscribe(user1);
	group->subscribe(user2);
	group->subscribe(user3);

	group->notify("Hello");

	group->unsubscribe(user2);

	group->notify("Bye");

	return 0;
}