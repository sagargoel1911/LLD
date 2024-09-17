#include <iostream>
using namespace std;

class Cone
{
public:
	virtual string getConstituents() = 0;
	virtual int getCost() = 0;
};

class OrangeCone : public Cone
{
public:
	string getConstituents()
	{
		return "Orange Cone";
	}
	int getCost()
	{
		return 20;
	}
};

class VanillaScoop : public Cone
{
public:
	Cone *BaseCone;
	VanillaScoop(Cone *cone)
	{
		this->BaseCone = cone;
	}
	string getConstituents()
	{
		return BaseCone->getConstituents() + ", Vanilla Scoop";
	}
	int getCost()
	{
		return BaseCone->getCost() + 5;
	}
};

int main()
{
	Cone *OurCone = new VanillaScoop(new VanillaScoop(new OrangeCone()));
	cout << OurCone->getConstituents() << endl;
	cout << OurCone->getCost() << endl;
	return 0;
}