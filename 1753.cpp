#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 100000;

int e, v, start;

vector<pair<int, int>> vct[100001]; // 간선 정보
int dist[100001]; // 최소 비용을 기록할 배열

void Dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (pq.empty() != true)
	{
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (dist[current] < cost) continue;

		for (int i = 0; i < vct[current].size(); i++)
		{
			int s = cost + vct[current][i].second;

			if (s < dist[vct[current][i].first])
			{
				dist[vct[current][i].first] = s;
				pq.push({-s, vct[current][i].first });
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> e >> v;
	cin >> start;

	for (int i = 0; i < v; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vct[a].push_back({ b,c });
	}
	fill(dist, dist + 100001, INF);

	Dijkstra(start);

	for (int i = 1; i <= e; i++)
	{
		if (dist[i] == INF)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << dist[i] << '\n';
		}
	}
	return 0;
}
