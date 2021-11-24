#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int>> qe; // BFS에 사용할 큐

// 상하좌우로 움직일 배열
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T; // 시행 횟수 입력
	while (T--)
	{
		int n, m, k; // 세로, 가로, 배추 개수
		cin >> m >> n >> k; // 입력
    
		vector<vector<int>> vat(n, vector<int>(m, 0)); // 밭 벡터
		vector<vector<bool>> visited(n, vector<bool>(m, false)); // 방문여부 벡터
		vector<pair<int, int>> location; // 검색 시간을 줄이기 위해 벡터를 하나 더 만듦
    
		int cnt = 0; // 지렁이 수 초기화
		for (int i = 0; i < k; i++)
		{
			int x, y; // 배추의 좌표
			cin >> x >> y;
			vat[y][x] = 1; // 벡터로 계산하므로 세로 가로로 배치한다.
			location.push_back({ y,x }); // 모든 위치를 검사하면 시간이 오래걸리므로 배추의 위치만 검사할 수 있도록 좌표를 기록한다.
		}

		for (int i = 0; i < location.size(); i++) // 배추의 좌표들만 조사한다.
		{
			if (visited[location[i].first][location[i].second] == true) continue; // 방문한 곳은 더 방문하지 않는다.
			
			qe.push({ location[i].first, location[i].second });
			visited[location[i].first][location[i].second]; // 방문했다고 표시한다
			cnt++; // 지렁이가 필요한 지점을 추가한다.
			// BFS 시작
			while (qe.empty() != true)
			{
				int cy = qe.front().first, cx = qe.front().second;  // 현재 위치
				qe.pop();

				for (int j = 0; j < 4; j++)
				{
					int nx = cx + dx[j];
					int ny = cy + dy[j];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // 범위 이탈 방지
					if (visited[ny][nx] == true || vat[ny][nx] == 0) continue; // 방문했거나 0인 지점일 경우 수행하지 않는다
          // 모든 조건을 통과한 경우
					qe.push({ ny, nx }); // 큐에 삽입한다.
					visited[ny][nx] = true; // 방문했다고 표시한다.
				}
			}
		}
		cout << cnt << '\n'; 출력한다
	}
	return 0;
}
