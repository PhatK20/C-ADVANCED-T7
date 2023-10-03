#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	cout << endl;
	cout << "Enter your username: " ;

	string userName;
	// cin.ignore();
	getline(cin, userName);

	cout << endl;
	cout << "Enter your password: " ;
	string password;
	cin.ignore();
	getline(cin, password);

     cout << endl;

     cout << userName << endl;
     cout << password << endl;
     return 0;
}
