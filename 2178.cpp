#include <iostream>
#include <string>
#include <queue>
using namespace std;

// 문제 번호: 2178(미로 탐색)

// 영역을 표시할 배열
string board[102];
// 시작점에서 거리를 측정할 배열
int dist[102][102];
// 영역을 제한할 변수
int n, m;
// 이동을 편하게 할 배열
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> q; // 큐 생성

int main()
{
	
	string s;

	// 영역 지정
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist[i][j] = -1;
		}
	}


	q.push({ 0,0 });
	int move = 0;
	dist[0][0] = move;
	while (q.empty() != true)
	{
		pair<int, int> cur = q.front(); q.pop(); // 현재 위치
		for (int i = 0; i < 4; i++)
		{
			// 다음 움직일 위치
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			// 오류 검사
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == '0') continue;
			// 오류 검사를 통과한 경우
			dist[nx][ny] = dist[cur.first][cur.second] +1;
			q.push({ nx, ny });
		}

	}
	
	// 시작점의 이동 거리를 0으로 잡았지만 문제에서는 1로 정해서 + 1을 해준다.
	cout << dist[n-1][m-1] + 1 << '\n';


	return 0;
}