// 11725: 트리의 부모 찾기
// 인접리스트(벡터 그래프)를 사용하는 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> qe;
vector<int> graph[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<bool> visited(100001, false);
	vector<int> ans(1000001, 0);
	int n; cin >> n;

	// 무방향 그래프 연결
	for (int i = 0; i < n-1; i++)
	{
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	qe.push(1); // 조건에 무조건 루트는 1이라고 했으므로
	visited[1] = true;
	while (qe.empty() != true) // 여기서 BFS 수행
	{
		int current = qe.front(); qe.pop();
		for (size_t i = 0; i < graph[current].size(); i++)
		{
			int next = graph[current][i];
			if (visited[next] == false)
			{
				ans[next] = current;
				visited[next] = true;
				qe.push(next);
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << ans[i] << '\n';
	}
}
