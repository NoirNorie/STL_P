// 11479: 통나무 건너뛰기

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> vc(n);
		for (size_t i = 0; i < vc.size(); i++) cin >> vc[i];
		sort(vc.begin(), vc.end());
		vector<int> tmp;

		if (vc.size() % 2 == 0)
		{
			for (int i = 0; i < vc.size(); i += 2) tmp.push_back(vc[i]);
			for (int i = vc.size() - 1; i > 0; i -= 2) tmp.push_back(vc[i]);
		}
		else
		{
			for (int i = 0; i < vc.size(); i += 2) 
				tmp.push_back(vc[i]);
			for (int i = vc.size() - 2; i > 0; i -= 2) 
				tmp.push_back(vc[i]);
		}
		int mx = 0;
		for (size_t i = 1; i < tmp.size(); i++)
		{
			mx = max(mx, abs(tmp[i] - tmp[i - 1]));
		}
		cout << mx << '\n';


	}
	
}
