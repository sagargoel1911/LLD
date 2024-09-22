#include <iostream>
#include <map>

using namespace std;

class PathCalculatorStratergy
{
public:
	virtual void calculatePath() const = 0;
};

class CarPathCalculator : public PathCalculatorStratergy
{
public:
	void calculatePath() const
	{
		cout << "We're calculating path for a Car\n";
	}
};

class BikePathCalculator : public PathCalculatorStratergy
{
public:
	void calculatePath() const
	{
		cout << "We're calculating path for a Bike\n";
	}
};

class PathCalculatorStratergyRegistry // we are using registry instead of factory as we do not want different instances every time as no need. Waste of space
{
	map<string, PathCalculatorStratergy *> mp;

public:
	void registerObj(string s, PathCalculatorStratergy *obj)
	{
		mp[s] = obj;
	}
	PathCalculatorStratergy *get(string s)
	{
		return mp[s];
	}
};

class Client
{
	PathCalculatorStratergyRegistry *registry;

public:
	Client(PathCalculatorStratergyRegistry *registry)
	{
		this->registry = registry;
	}
	void findPath(string mode)
	{
		PathCalculatorStratergy *travelMode = registry->get(mode);
		travelMode->calculatePath();
	}
};

int main()
{
	PathCalculatorStratergyRegistry *registry = new PathCalculatorStratergyRegistry();
	registry->registerObj("Car", new CarPathCalculator());
	registry->registerObj("Bike", new BikePathCalculator());

	Client *client = new Client(registry);

	client->findPath("Car");
	client->findPath("Bike");

	// Very easy problem statement: There are multiple was of solving a problem/ doing something. How to implement it? Here's the answer.
	return 0;
}