// 9237: 이장님 초대
// 간단한 그리디 알고리즘 문제

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> vct(n);
	for (size_t i = 0; i < vct.size(); i++)	cin >> vct[i];

	sort(vct.begin(), vct.end(), greater<int>());

	int day = 1;
	int mx = 0;
	for (size_t i = 0; i < vct.size(); i++, day++)
	{
		mx = max(mx, vct[i] + day);
	}
	cout << mx +1<< '\n';
}
