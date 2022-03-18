// 7562: 나이트의 이동

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[] = {-2, -1, 1, 2, 2, 1,-1,-2};

queue<pair<pair<int, int>, int>> qe; // BFS를 수행할 큐

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	while (n--)
	{
		int l; cin >> l;
		vector<vector<bool>> mp(l, vector<bool>(l, false));
		int x, y, tx, ty;
		cin >> x >> y;
		cin >> tx >> ty;

		int cnt = 0;

		qe.push({{ y,x }, cnt});
		mp[y][x] = true;
		while (qe.empty() != true)
		{
			int cy = qe.front().first.first, cx = qe.front().first.second;
			int ccnt = qe.front().second;
			if (cy == ty && cx == tx)
			{
				cout << ccnt << '\n';                 // 가장 먼저 나온 값이 최소횟수가 된다 (BFS로 풀었으므로)
				while (qe.empty() != true) qe.pop();  // 재사용하기 위해서 큐를 초기화해준다 (큐는 clear 함수가 없음)
				break;
			}
			qe.pop();
			for (int i = 0; i < 8; i++)
			{
				int ny = cy + dy[i], nx = cx + dx[i];
				if (ny < 0 || nx < 0 || ny >= l || nx >= l) continue;
				if (mp[ny][nx] == true) continue;
				mp[ny][nx] = true;
				qe.push({ { ny, nx }, ccnt+1});
			}
		}
	}
}
