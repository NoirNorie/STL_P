// 2589: 보물섬
// 브루트포스 범주에 존재하기는 하지만 BFS 문제에 더 가깝다
// 모든 지점을 검사해야 한다는 의미에서 브루트포스 인가 싶기도 하다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

queue<pair<int,int>> qe;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	vector<vector<int>> mp(n, vector<int>(m)), bf(n, vector<int>(m));
	for (size_t i = 0; i < mp.size(); i++)
	{
		for (size_t j = 0; j < mp[i].size(); j++)
		{
			char x; cin >> x;
			if (x == 'W') mp[i][j] = -1;
			else mp[i][j] = 0;
		}
	}
	int mx = 0;
	for (size_t i = 0; i < mp.size(); i++)
	{
		for (size_t j = 0; j < mp[i].size(); j++)
		{
			if (mp[i][j] == -1) continue;
			else
			{
				bf = mp;          // BFS를 수행할 사본 벡터
				qe.push({ i,j }); // 해당 위치에서 BFS를 수행한다.

				bf[i][j] = 1;
				while (qe.empty() != true)
				{
					int cy = qe.front().first;
					int cx = qe.front().second;
					qe.pop();
					for (int i = 0; i < 4; i++)
					{
						int nx = cx + dx[i];
						int ny = cy + dy[i];
						if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
						if (bf[ny][nx] != 0) continue;
						bf[ny][nx] = bf[cy][cx] + 1;
						qe.push({ ny, nx });
						mx = max(mx, bf[ny][nx] -1);
					}
				}
			}
		}
	}
	cout << mx << '\n';

}
