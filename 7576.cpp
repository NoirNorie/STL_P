#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int>> qe;
queue<pair<int, int>> tmpq;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> m >> n; // 세로 가로 입력

	vector<vector<int>> box(n, vector<int>(m)); // 박스 생성

	// 박스의 상태를 입력받는다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
		}
	}

	// 방문 배열이 필요 없다
	// 1인 부분을 점검하지 않으면 된다.

	// 1인 부분을 찾는다
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 1)
				qe.push({ i, j }); // BFS를 동작시킬 준비를 한다.
		}
	}
	int day = 0;
	while (qe.empty() != true || tmpq.empty() != true)
	{
		// 현재 좌표
		int cy = qe.front().first;
		int cx = qe.front().second;
		qe.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // 범위 이탈 방지
			if (box[ny][nx] == -1 || box[ny][nx] == 1) continue; // 빈 곳이거나 이미 익은 곳이라면 생략한다.

			// 조건을 만족했다면
			tmpq.push({ ny, nx }); // 임시 큐에 넣는다.
			box[ny][nx] = 1; // 익었다고 표시한다.
		}

		if (qe.empty() == true)
		{			
			if (tmpq.empty() != true) //  임시 큐에 다음 토마토가 있다면
			{
				while (tmpq.empty() != true) // BFS 큐에 넣는다.
				{
					qe.push(tmpq.front()); tmpq.pop();
				}
				day++; // 날짜도 증가시킨다.
			}
		}
	}

	bool chk = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 0)
			{			
				chk = true;
				break;
			}
		}
		if (chk == true) break;
	}
	if (chk == true)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << day << '\n';
	}
}
