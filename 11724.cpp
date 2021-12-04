#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> qe; // BFS에 사용할 큐
vector<int> graph[1001]; // 그래프로 사용할 벡터

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
 
    vector<bool> visited(n + 1); // 방문 여부를 저장할 벡터

    for (int i = 0; i < m; i++) // 그래프 생성
    {
        int st, dt; cin >> st >> dt;
        graph[st].push_back(dt);
        graph[dt].push_back(st);
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true) continue; // 방문한 곳은 BFS 단계로 넘어가지 않는다.

        visited[i] = true;
        qe.push(i);
        while (qe.empty() != true)
        {
            int current = qe.front(); qe.pop();
            for (int t = 0; t < graph[current].size(); t++)
            {
                if (visited[graph[current][t]] == true) continue; // 방문한 곳은 큐에 들어가지 못하게 막는다.
                visited[graph[current][t]] = true;
                qe.push(graph[current][t]); // 다음에 동작할 부분
            }

        }
        cnt++;
    }

    cout << cnt << '\n';

	return 0;
}
