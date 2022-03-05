#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
// 굳이 우선순위 큐를 써야 하나 싶다.
// 정렬 과정이 없어서 그런가
int main()
{
	int n; cin >> n;
	vector<int> result;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		pq.push(x);
	}
	while (pq.size() >= 2)
	{
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		pq.push(x + y);
		result.push_back(x + y);
	}
	int answer = 0;
	for (auto e : result) answer += e;
	cout << answer << '\n';
}
