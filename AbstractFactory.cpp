#include <iostream>

using namespace std;

class Button
{
public:
	virtual ~Button() {}
	virtual void say() = 0;
};

class MacButton : public Button
{
public:
	void say()
	{
		cout << "Mac Button" << endl;
	}
};

class WindowsButton : public Button
{
public:
	void say()
	{
		cout << "Windows Button" << endl;
	}
};

class TextBox
{
public:
	virtual ~TextBox() {}
	virtual void say() = 0;
};

class MacTextBox : public TextBox
{
public:
	void say()
	{
		cout << "Mac Text Box" << endl;
	}
};

class WindowsTextBox : public TextBox
{
public:
	void say()
	{
		cout << "Windows Text Box" << endl;
	}
};

class FactoryInterface
{
public:
	virtual ~FactoryInterface() {}
	virtual Button *createButton() = 0;
	virtual TextBox *createTextBox() = 0;
};

class MacFactory : public FactoryInterface
{
public:
	Button *createButton()
	{
		return new MacButton();
	}
	TextBox *createTextBox()
	{
		return new MacTextBox();
	}
};

class WindowsFactory : public FactoryInterface
{
public:
	Button *createButton()
	{
		return new WindowsButton();
	}
	TextBox *createTextBox()
	{
		return new WindowsTextBox();
	}
};

class GUIFactory
{
public:
	static FactoryInterface *createFactory(string type)
	{
		if (type == "Windows")
		{
			return new WindowsFactory();
		}
		else
		{
			return new MacFactory();
		}
	}
};

int main()
{
	FactoryInterface *factory = GUIFactory::createFactory("Windows");
	Button *button = factory->createButton();
	button->say();
}