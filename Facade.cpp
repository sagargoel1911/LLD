#include <iostream>
using namespace std;

class SubSystem1
{
public:
	string Operation1() const
	{
		return "Subsystem1: Ready!\n";
	}
	string OperationZ() const
	{
		return "Subsystem2: Fire!\n";
	}
};

class SubSystem2
{
public:
	string Operation1() const
	{
		return "Subsystem2: Ready!\n";
	}
	string OperationG() const
	{
		return "Subsystem2: Go!\n";
	}
};

class Facade
{
	SubSystem1 *_subsystem1;
	SubSystem2 *_subsystem2;

public:
	Facade(
		SubSystem1 *subsystem1 = nullptr,
		SubSystem2 *subsystem2 = nullptr)
	{
		this->_subsystem1 = subsystem1 ? subsystem1 : new SubSystem1;
		this->_subsystem2 = subsystem2 ? subsystem2 : new SubSystem2;
	}
	~Facade()
	{
		delete _subsystem1;
		delete _subsystem2;
	}
	string Operation()
	{
		string result = "Facade initializes subsystems:\n";
		result += _subsystem1->Operation1();
		result += _subsystem1->OperationZ();
		result += "Facade orders subsystems to perform the action:\n";
		result += this->_subsystem1->Operation1();
		result += this->_subsystem2->OperationG();
		return result;
	}
};

void Client(Facade *facade)
{
	cout << facade->Operation();
}

int main()
{
	Facade *facade = new Facade();
	Client(facade);

	// Client can access subsystems directly or can use Facade for simplicity
	return 0;
}