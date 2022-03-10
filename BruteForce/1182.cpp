// 1182: 부분수열의 합

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, s; cin >> n >> s;
	int cnt = 0;
	vector<int>v(n, 0);
	for (size_t i = 0; i < v.size(); i++) cin >> v[i];
	vector<int>sel(n, 0);
	for (size_t i = 0; i < sel.size(); i++)
	{
		sel[0] = 1;
		sort(sel.begin(), sel.end());
		do
		{
			int sum = 0;
			for (size_t i = 0; i < sel.size(); i++)
			{
				if (sel[i] == 1) sum += v[i];
			}
			if (sum == s) cnt++;

		} while (next_permutation(sel.begin(), sel.end()));
	}

	cout << cnt << '\n';
}
