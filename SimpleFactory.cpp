#include <iostream>
using namespace std;

class Person
{
public:
	virtual void tell()
	{
		cout << "Person" << endl;
	}
};

class User : public Person
{
public:
	void tell()
	{
		cout << "User" << endl;
	}
};

class Customer : public Person
{
public:
	void tell()
	{
		cout << "Customer" << endl;
	}
};

class Admin : public Person
{
public:
	void tell()
	{
		cout << "Admin" << endl;
	}
};

class PersonFactory
{
public:
	Person *createPerson(string type)
	{
		if (type == "Admin")
		{
			return new Admin();
		}
		else if (type == "Customer")
		{
			return new Customer();
		}
		else if (type == "User")
		{
			return new User();
		}
		return new Person();
	}
};

int main()
{
	PersonFactory *personFactory = new PersonFactory();
	Person *person = personFactory->createPerson("Admin");
	person->tell();

	return 0;
}