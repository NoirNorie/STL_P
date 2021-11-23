#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;


vector<pair<int, int>> graph[100001]; // 인접 리스트 생성
int N, M; // 섬 수, 다리 수
int start, finish; // 시작지점, 도착지점
vector<bool> visited;

bool BFS(int limit)
{
	queue<int> qe;
	qe.push(start);

	visited[start] = true;


	while (qe.empty() != true)
	{
		int current = qe.front(); qe.pop();

		if (current == finish) return true; // 목적지에 도달했다면

		for (int i = 0; i < graph[current].size(); i++)
		{
			int island = graph[current][i].first;
			int bridge_limit = graph[current][i].second;

			if (bridge_limit < limit) continue; // 무게 제한에 걸린다면
			if (visited[island] == true) continue; // 지나온 섬이라면

			//조건을 통과했다면
			visited[island] = true;
			qe.push(island);
		}
	}
	// 여기까지 오면 목적지에 도달하지 못한 것
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int mx_limit = 0;
	for (int i = 0; i < m; i++) // 다리 수 만큼 인접 리스트를 연결해준다.
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });

		mx_limit = max(mx_limit, c);
	}

	cin >> start >> finish;

	int l = 0;
	int mx = mx_limit;

	while (l <= mx)
	{
		visited.assign(n + 1, false);

		int mid = (l + mx) / 2;

		if (BFS(mid) == true)
		{
			l = mid + 1;
		}
		else
		{
			mx = mid - 1;
		}
	}
	cout << mx << '\n';

	return 0;
}
