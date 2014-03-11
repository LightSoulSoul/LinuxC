/*#include <iostream>

class Message
{
public:
	//folders is initialized to the empty set automatically
	Message(const std::string &str = ""):
			contents(str){ }
	Message(const Message&);
	Message& operator=(const Message &);
	~Message();

	void save (Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;
	void put_Msg_in_Folders();
	void remove_Msg_form_Folders();
};

Message::Message(const Message &m):
		contents(m.contents), folders(m.contents)
{
	put_Msg_in_Folders(folders);
}

void Message::put_Msg_in_Folders(const set<Folder*> &rhs)
{
	for (std::set<Folder*>::const_iterator beg = rhs.begin(); beg != rhs.end(); ++beg)
	{
		(*beg)->addMsg(this);
	}
}

Message& Message::operator=(const Message &rhs)
{
	if (&rhs != this)
	{
		remove_Msg_form_Folders();
		contents = rhs.contents;
		folders = rhs.folders;
		put_Msg_in_Folders(rhs.folders);
	}
	return *this;
}

void Message::remove_Msg_form_Folders()
{
	for (std::set<Folder*>::const_iterator beg = folders.begin(); beg != folders.end(); ++beg)
	{
		(*beg)->remMsg(this);
	}
}

Message::~Message()
{
	remove_Msg_form_Folders();
}
*/
#include <iostream>
using namespace std;

class Base
{
public:
	Base() { }
	~Base() { }
	virtual void print()
	{ cout << "Base" << endl; }
};

class A : public Base
{
public:
	void print()
	{ cout << "A" << endl; }
	A() { }
	~A() { }
};

int main()
{
	Base* p;
	A a;
	p = &a;
	a->print();
	return 0;
}














