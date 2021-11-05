#include <iostream>
#include <queue>
using namespace std;

// ���� ��ȣ: 1926(�׸�)
// BFS ����

// ������ ǥ���� �迭
int board[502][502];
// �湮 ���θ� ����� �迭
bool visited[502][502];
// ������ ������ �迭
int n, m;
// �����¿�� �����̱� ���ϰ� �ϱ� ���� �迭
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	queue<pair<int, int>> q;

	cin >> n >> m;

	int max = 0; // ���� ���� ������ ����� ����
	int cnt = 0; // �׸��� ������ �� ����

	// ���� ������ �Է¹޴´�.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	// �׸��� ã�ư���.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// ��ĥ�� �κ��ε� �湮���� ���� �����̶��
			if (board[i][j] == 1 && visited[i][j] == false)
			{
				// ���⼭ BFS�� �����Ѵ�.
				visited[i][j] = true;
				q.push({ i,j });
				
				int size = 1; // ������ �������� ũ�⸦ ����
				cnt++; // ���� �ϳ��� �߰����ش�.

				while (q.empty() != true)
				{
					// ���� ��ǥ ����
					pair<int, int> cur = q.front(); q.pop();
					for (int t = 0; t < 4; t++)
					{
						// ���� ��ǥ ����
						int nx = cur.first + dx[t];
						int ny = cur.second + dy[t];

						// ���� �ʰ� ó��
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						// �湮�� �����̰ų� ��ĥ�� �κ��� �ƴ� �κ� ó��
						if (visited[nx][ny] == true || board[nx][ny] == 0) continue;

						// ������ �� ��������� �̵� ������ �����̹Ƿ�
						visited[nx][ny] = true;
						q.push({ nx, ny });
						size++;
					}
				}

				// BFS�� ����� �� ũ�⸦ ���Ѵ�.
				if (size > max) max = size;
			}

		}
	}

	// ��� ���
	cout << cnt << '\n';
	cout << max << '\n';
	

	return 0;
}