// 11000: 강의실 배정
// 추가적인 공부가 필요한 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> vt(n);
	for (size_t i = 0; i < vt.size(); i++) cin >> vt[i].first >> vt[i].second;
	sort(vt.begin(), vt.end());

	pq.push(vt[0].second);
	for (int i = 1; i < n; i++)
	{
		if (pq.top() <= vt[i].first)
		{
			pq.pop();
			pq.push(vt[i].second);
		}
		else
		{
			pq.push(vt[i].second);
		}
	}
	cout << pq.size() << '\n';

}
