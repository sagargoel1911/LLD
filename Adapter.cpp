#include <iostream>
using namespace std;

class Adaptee
{ // 3rd party stuff, foreign thing to which our code will adapt too
public:
	string SpecificRequest()
	{
		return ".eetpadA eht fo roivaheb laicepS";
	}
};

class Adaptee2
{ // 3rd party stuff, foreign thing to which our code will adapt too
public:
	string SpecificRequest()
	{
		return "Just return it normally.";
	}
};

class RequestAnswerer
{ // Interface which our client will reach out to
public:
	virtual string Request()
	{
		return "Target: The default target's behavior.";
	}
};

class Adapter : public RequestAnswerer
{ // concrete version of the adapter, an intermediary
	Adaptee *a;

public:
	string Request()
	{
		string ans = a->SpecificRequest();
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

class Adapter2 : public RequestAnswerer
{ // concrete version of the adapter, an intermediary. Corresponds to 2nd Adaptee
	Adaptee2 *a;

public:
	string Request()
	{
		string ans = a->SpecificRequest();
		return ans;
	}
};

class Client
{
	// Our Code/ Client code which we do not want change in
	RequestAnswerer *r;

public:
	Client(RequestAnswerer *r)
	{
		this->r = r;
	}
	string Request()
	{
		return r->Request();
	}
};
int main()
{
	// Client *c = new Client(new Adapter());
	Client *c = new Client(new Adapter2());
	cout << c->Request() << endl;

	// The only thing we had to change in the code is the Adapter being sent
	// Make 1 adapter for each adaptee
	// So Open Close principle is followed here
	return 0;
}