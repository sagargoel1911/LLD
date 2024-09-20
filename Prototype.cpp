#include <iostream>
using namespace std;

class PrototypeInterface
{
public:
	virtual PrototypeInterface *clone() = 0;
	virtual ~PrototypeInterface() {}
};

class ConcretePrototype1 : public PrototypeInterface
{
public:
	PrototypeInterface *clone()
	{
		cout << "Create Prototype 1" << endl;
		return new ConcretePrototype1(*this); // Using copy constructor to make a copy
	}
};

class ConcretePrototype2 : public PrototypeInterface
{
public:
	PrototypeInterface *clone()
	{
		cout << "Create Prototype 2" << endl;
		return new ConcretePrototype2(*this); // Using copy constructor to make a copy
	}
};

class PrototypeFactory
{
	unordered_map<string, PrototypeInterface *> u;

public:
	PrototypeFactory()
	{
		u["Prototype1"] = new ConcretePrototype1();
		u["Prototype2"] = new ConcretePrototype2();
	}
	PrototypeInterface *CreatePrototype(string type)
	{
		return u[type]->clone();
	}
};

void Client(PrototypeFactory &prototype_factory)
{

	PrototypeInterface *prototype = prototype_factory.CreatePrototype("Prototype1");
	delete prototype;

	prototype = prototype_factory.CreatePrototype("Prototype2");
	delete prototype;
}

int main()
{
	PrototypeFactory *prototypeFactory = new PrototypeFactory();
	Client(*prototypeFactory);
	return 0;
}