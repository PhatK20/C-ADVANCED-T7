#include <iostream>
#include <memory>

using namespace std;
class MyClass
{
public:
	void PrintMessage()
	{
		cout << "Hello from MyClass!" << endl;
	}
};

int main()
{
	shared_ptr<MyClass> sharedPtr = make_shared<MyClass>();
	weak_ptr<MyClass> weakPtr = sharedPtr;

	// Check if the object still exists
	if (auto lockedPtr = weakPtr.lock())
	{
		lockedPtr->PrintMessage();
	}
	else
	{
		cout << "The object has been destroyed." << endl;
	}

	// Now, release the sharedPtr
	sharedPtr.reset();

	// Check again
	if (auto lockedPtr = weakPtr.lock())
	{
		lockedPtr->PrintMessage();
	}
	else
	{
		cout << "The object has been destroyed." << endl;
	}

	return 0;
}
