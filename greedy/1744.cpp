// 1744: 수 묶기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> p, m;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (x > 0) p.push_back(x);
		else m.push_back(x);
	}
	sort(p.begin(), p.end(), greater<int>());
	sort(m.begin(), m.end());

	vector<int> result;

	for (size_t i = 0; i < p.size(); i++)
	{
		if (p[i] == 1 || i == p.size()-1) result.push_back(p[i]);
		else
		{
			if (p[i + 1] == 1) result.push_back(p[i]);
			else
			{
				result.push_back(p[i] * p[i + 1]);
				i++;
			}
		}
	}

	for (size_t i = 0; i < m.size(); i++)
	{
		if (i != m.size() - 1)
		{
			result.push_back(m[i] * m[i + 1]);
			i++;
		}
		else result.push_back(m[i]);
	}


	int ans = 0;
	for (auto e : result) ans += e;
	cout << ans;
}
