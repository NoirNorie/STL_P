// 1759: 암호 만들기

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

set<string> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int L, C; cin >> L >> C;
	
	vector<string> alp(C);
	for (int i = 0; i < C; i++) cin >> alp[i];
	
	vector<int> selector(C, 0);
	for (size_t i = 0; i < L; i++) selector[i] = 1;
	
	sort(selector.begin(), selector.end());
	do
	{
		string tmp = "";
		for (size_t i = 0; i < selector.size(); i++)
		{
			if (selector[i] == 1)
			{
				tmp += alp[i];
			}
		}
		sort(tmp.begin(), tmp.end());
		st.insert(tmp);

	} while (next_permutation(selector.begin(), selector.end()));

	for (auto e : st)
	{
		if (e.length() < L) continue;
		else if (e.length() > L) break; // 사실 이 부분은 필요 없다, 위에서 해당 개수만큼만 골랐기 때문, 하지만 넣었다.
		else
		{
			int mo = 0, ja = 0;
			for (size_t i = 0; i < e.length(); i++)
			{
				if (e[i] == 'a' || e[i] == 'i' || e[i] == 'e' || e[i] == 'o' || e[i] == 'u') mo++;
				else ja++;
			}
			if (mo >= 1 && ja >= 2) cout << e << '\n'; // 부등호에 신경쓰자
		}
	}
}
