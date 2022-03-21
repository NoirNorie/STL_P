// 11286: 절대값 힙
// 우선순위 큐를 이용하여 처리함
// 세트를 사용해도 될 거 같긴 함

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int>b)
	{
		if (a.first > b.first) // 절대값이 작은 것이 먼저
		{
			return true;
		}
		else if (a.first == b.first)
		{
			if (a.second > b.second) return true;
			else return false;
		}
		else
		{
			return false;
		}
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	int n; cin >> n;
	while (n--)
	{
		int x; cin >> x;
		if (x == 0)
		{
			if (pq.empty() != true)
			{
				cout << pq.top().second << '\n';
				pq.pop();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else
		{
			pq.push({ abs(x), x });
		}
	}
}
