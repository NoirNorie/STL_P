// 2864: 5와 6의 차이

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b; cin >> a >> b;
	string amn = "", amx = "", bmn = "", bmx = "";

	for (size_t i = 0; i < a.length(); i++)
	{
		if (a[i] == '6' || a[i] == '5')
		{
			amn += '5';
			amx += '6';
		}
		else
		{
			amn += a[i];
			amx += a[i];
		}
	}
	for (size_t i = 0; i < b.length(); i++)
	{
		if (b[i] == '6' || b[i] == '5')
		{
			bmn += '5';
			bmx += '6';
		}
		else
		{
			bmn += b[i];
			bmx += b[i];
		}
	}
	int mn = stoi(amn) + stoi(bmn);
	int mx = stoi(amx) + stoi(bmx);
	cout << mn << " " << mx << '\n';
}
