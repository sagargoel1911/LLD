#include <iostream>
using namespace std;

class Target
{
	int a, b, c;
	Target() {};

public:
	friend class Builder;
	void tellState()
	{
		cout << a << endl
			 << b << endl
			 << c << endl;
	}
};

class Builder
{
	int a, b, c;

public:
	Builder *setA(int a)
	{
		this->a = a;
		return this;
	}
	Builder *setB(int b)
	{
		this->b = b;
		return this;
	}
	Builder *setC(int c)
	{
		this->c = c;
		return this;
	}
	Target *build()
	{
		// validate
		Target *t = new Target();
		// copy value
		t->a = this->a;
		t->b = this->b;
		t->c = this->c;
		return t;
	}
};

int main()
{
	Builder *b = new Builder();
	Target *t = b->setA(5)->setB(6)->setC(7)->build();
	t->tellState();
	return 0;
}