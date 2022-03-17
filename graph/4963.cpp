// 4963: 섬의 개수

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

queue<pair<int, int>> qe;

int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (true)
	{
		int w, h; cin >> w >> h;
		if (w == 0 && h == 0) break;
		else
		{
			vector<vector<int>> mp(h, vector<int>(w, 0));
			vector<vector<bool>> visited(h, vector<bool>(w, false));
			for (size_t i = 0; i < mp.size(); i++) for (size_t j = 0; j < mp[i].size(); j++) cin >> mp[i][j];

			int cnt = 0;

			for (size_t i = 0; i < mp.size(); i++)
			{
				for (size_t j = 0; j < mp[i].size(); j++)
				{
					if (mp[i][j] != 1 || visited[i][j] == true) continue;
					else
					{
						cnt++;
						qe.push({ i, j }); // DFS 시작
						visited[i][j] = true;
						while (qe.empty() != true)
						{
							int cy = qe.front().first, cx = qe.front().second;
							qe.pop();

							for (int t = 0; t < 8; t++)
							{
								int ny = cy + dy[t], nx = cx + dx[t];
								if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
								if (mp[ny][nx] == 0) continue;
								if (visited[ny][nx] == true) continue;
								visited[ny][nx] = true;
								qe.push({ ny, nx });
							}

						}
					}
				}
			}
			cout << cnt << '\n';
		}
	}
}
