#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	string s; cin >> s;

	n--;
	while ((n)--)
	{
		string c; cin >> c;
		for (int i = 0; i < s.length(); i++)
		{
			if(s[i] != c[i])
			{ 
				s[i] = '?';
			}
		}
	}

	cout << s << '\n';

	return 0;
}
