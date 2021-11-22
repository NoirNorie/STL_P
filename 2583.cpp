#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int>> qe;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;
	vector<vector<int>> area(m, vector<int>(n, 0)); // 공간 생성
	vector<vector<int>> blck(k, vector<int>(4)); // 좌표
	vector<vector<bool>> visited(m, vector<bool>(n, false));

	for (int i = 0; i < blck.size(); i++)
	{
		cin >> blck[i][0] >> blck[i][1] >> blck[i][2] >> blck[i][3];
	}

	// 구역 표시
  // 사각형에 1을 표시해야 하므로 우상단의 좌표보다 x, y가 1씩 작아야 한다
	for (int i = 0; i < blck.size(); i++)
	{
		for (int j = blck[i][0]; j <= blck[i][2] - 1; j++)
		{
			for (int t = blck[i][1]; t <= blck[i][3] - 1; t++)
			{
				area[t][j] = 1;
			}
		}
	}
	
	
	int cnt = 0;
	vector<int> sv;
	for (int i = 0; i < area.size(); i++)
	{
		for (int j = 0; j < area[i].size(); j++)
		{
			if (area[i][j] == 0 && visited[i][j] == false)
			{
				cnt++;
				int size = 1;
				visited[i][j] = true; // 방문 표시
				
				// BFS 시작
				qe.push({ i, j });
				while (qe.empty() != true)
				{
					int cy = qe.front().first;
					int cx = qe.front().second;
					qe.pop();

					for (int t = 0; t < 4; t++)
					{
						int nx = cx + dx[t];
						int ny = cy + dy[t];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (area[ny][nx] != 0 || visited[ny][nx] == true) continue;

						visited[ny][nx] = true;
						qe.push({ ny, nx });
						size++;
					}

				}
				sv.push_back(size);
			}
		}
	}

	sort(sv.begin(), sv.end());

	cout << cnt << '\n';
	for (auto e : sv) cout << e << " ";

	return 0;
}
