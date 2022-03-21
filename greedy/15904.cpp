// 15904: UCPC는 무엇의 줄임말일까
// 고민해봤는데 중간에 검사용 출력을 지우지 않아서 틀렸음

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str; getline(cin, str);
	vector<char> vs;
	vector<char> vc = { 'U', 'C', 'P', 'C' };

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == 'U' || str[i] == 'C' || str[i] == 'P') vs.push_back(str[i]);
	}
	bool chk = false;
	int idx = 0;

	for (size_t i = 0; i < vs.size(); i++)
	{
		if (vs[i] == vc[idx])
		{
			idx++;
			if (idx == 4)
			{
				chk = true;
				break;
			}
		}
	}
	if (chk == true) cout << "I love UCPC" << '\n';
	else			 cout << "I hate UCPC" << '\n';

}
