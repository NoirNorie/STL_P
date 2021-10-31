#include <iostream>
#include <string>
using namespace std;

int main()
{
	string inp;
	getline(cin, inp, '\n');

	if (inp.find("d2") != -1 || inp.find("D2") != -1)
	{
		cout << "D2" << '\n';
	}
	else
	{
		cout << "unrated" << '\n';
	}
	return 0;
}