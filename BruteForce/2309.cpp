# 2309 : 일곱 난쟁이

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v(9, 0);
	for (size_t i = 0; i < v.size(); i++) cin >> v[i];
	vector<int> sel = { 0,0,1,1,1,1,1,1,1 };
	vector<int> result;
	do
	{
		int n = 0;

		for (int i = 0; i < sel.size(); i++)
		{
			if (sel[i] == 1)
			{
				n += v[i];
				result.push_back(v[i]);
			}
		}
		if (n == 100) break;
		result.clear();

	} while (next_permutation(sel.begin(), sel.end()));

	sort(result.begin(), result.end());
	for (auto e : result) cout << e << '\n';
}
