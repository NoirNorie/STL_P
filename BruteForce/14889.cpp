# 14889: 스타트와 링크

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	for (size_t i = 0; i < v.size(); i++) for (size_t j = 0; j < v[i].size(); j++) cin >> v[i][j];

	vector<int> sel(n, 0);
	for (int i = 0; i < sel.size() / 2; i++) sel[i] = 1;
	sort(sel.begin(), sel.end());

	int m = 99999;
	vector<int> st, lk;
	do
	{
		int start = 0, link = 0;
		for (size_t i = 0; i < sel.size(); i++)
		{
			if (sel[i] == 1) st.push_back(i);
			else lk.push_back(i);
		}

		for (size_t i = 0; i < st.size(); i++)
		{
			for (size_t j = i; j < st.size(); j++)
			{
				start += (v[st[i]][st[j]] + v[st[j]][st[i]]);
				link += (v[lk[i]][lk[j]] + v[lk[j]][lk[i]]);
			}
		}
		st.clear(); lk.clear();
		m = min(m, abs(start - link));
	} while (next_permutation(sel.begin(), sel.end())); // next_permutation과 조합을 이용해서 백트래킹 과정을 대체한다.
	cout << m << '\n';
}
