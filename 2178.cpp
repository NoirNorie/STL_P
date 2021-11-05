#include <iostream>
#include <string>
#include <queue>
using namespace std;

// ���� ��ȣ: 2178(�̷� Ž��)

// ������ ǥ���� �迭
string board[102];
// ���������� �Ÿ��� ������ �迭
int dist[102][102];
// ������ ������ ����
int n, m;
// �̵��� ���ϰ� �� �迭
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> q; // ť ����

int main()
{
	
	string s;

	// ���� ����
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
		pair<int, int> cur = q.front(); q.pop(); // ���� ��ġ
		for (int i = 0; i < 4; i++)
		{
			// ���� ������ ��ġ
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			// ���� �˻�
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == '0') continue;
			// ���� �˻縦 ����� ���
			dist[nx][ny] = dist[cur.first][cur.second] +1;
			q.push({ nx, ny });
		}

	}
	
	// �������� �̵� �Ÿ��� 0���� ������� ���������� 1�� ���ؼ� + 1�� ���ش�.
	cout << dist[n-1][m-1] + 1 << '\n';


	return 0;
}