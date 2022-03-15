// 3109: 빵집

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dx[] = { 1,1, 1 };
int dy[] = { -1, 0,1 };
int n, m;
int cnt = 0;
vector<vector<int>> mp;

bool bfs(int r, int c)
{
	if (c == m - 1)
	{
		cnt++;
		return true;
	}
	mp[r][c] = 1;
	for (int i = 0; i < 3; i++)
	{
		int ny = dy[i] + r;
		int nx = dx[i] + c;
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (mp[ny][nx] == 1) continue;
		if (bfs(ny, nx) == true) return true;
	}
	return false;
}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	mp.assign(n, vector<int>(m));

	for (size_t i = 0; i < mp.size(); i++)
	{
		for (size_t j = 0; j < mp[i].size(); j++)
		{
			char x; cin >> x;
			if (x == '.') mp[i][j] = 0;
			else mp[i][j] = 1;
		}
	}
	for (size_t i = 0; i < mp.size(); i++)
	{
		bfs(i, 0);
	}
	cout << cnt << '\n';

}
