// 1259: 팰린드롬 수

#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while(1)
	{

		string s; cin >> s;
		if (s == "0") break;
		
		bool chk = true;
		for (size_t i = 0; i < s.length() / 2; i++)
		{
			if (s[i] != s[s.length() - i - 1])
			{
				chk = false;
				break;
			}
		}
		if (chk == true) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

}
