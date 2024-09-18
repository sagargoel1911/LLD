#include <iostream>
using namespace std;

class Query
{
public:
	virtual void tell()
	{
		cout << "Query" << endl;
	}
};

class UserQuery : public Query
{
public:
	void tell()
	{
		cout << "User Query" << endl;
	}
};

class CustomerQuery : public Query
{
public:
	void tell()
	{
		cout << "Customer Query" << endl;
	}
};

class AdminQuery : public Query
{
public:
	void tell()
	{
		cout << "Admin Query" << endl;
	}
};

class Person
{
public:
	virtual void createQuery() = 0;
};

class User : public Person
{
public:
	void createQuery()
	{
		Query *q = new UserQuery();
		q->tell();
	}
};

class Customer : public Person
{
public:
	void createQuery()
	{
		Query *q = new CustomerQuery();
		q->tell();
	}
};

class Admin : public Person
{
public:
	void createQuery()
	{
		Query *q = new AdminQuery();
		q->tell();
	}
};

int main()
{
	Person *p = new User();
	p->createQuery();

	return 0;
}