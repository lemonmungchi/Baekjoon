#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	while (1)
	{
		string s;
		getline(cin, s);

		if (s == "") break;

		cout << s << endl;
	}
	

	return 0;
}