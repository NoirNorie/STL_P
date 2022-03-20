// 14503: 로봇 청소기
// 귀찮은 것만 뺀다면 쉬운 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 이동 배열
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int r, c, d; cin >> r >> c >> d;
	vector<vector<int>> vc(n, vector<int>(m));
	for (size_t i = 0; i < vc.size(); i++) for (size_t j = 0; j < vc[i].size(); j++) cin >> vc[i][j];

	int cnt = 0;
	int ans = 0;
	while (true)
	{
		// 1: 현재 위치를 청소한다.
		if (vc[r][c] == 0)
		{
			vc[r][c] = 2;
			ans++;
		}
		else
		{
			// 2: 왼쪽 방향부터 차례로 인접한 칸을 탐색한다.
			if (cnt != 4)
			{
				if (d == 0) d = 3;
				else if (d == 1) d = 0;
				else if (d == 2) d = 1;
				else d = 2;

				// 왼쪽에 청소하지 않은 공간이 존재한다면 그 방향으로 회전하고 전진한다
				if (vc[r + dy[d]][c + dx[d]] == 0)
				{
					r += dy[d], c += dx[d];
					cnt = 0;
				}
				else cnt++; // 아니면 회전만 한다 
			}
			else // 네 방향을 모두 체크한 경우
			{
				int back;
				if (d == 0) back = 2;
				else if (d == 1) back = 3;
				else if (d == 2) back = 0;
				else back = 1;

				// 네 방향 모두 청소되어 있고, 뒤가 벽인 경우 종료
				if (vc[r + dy[back]][c + dx[back]] == 1) 
				{
					cout << ans << '\n';
					break;
				}
				else
				{
					r += dy[back], c += dx[back];
					cnt = 0;
				}
			}
		}
	}
}
