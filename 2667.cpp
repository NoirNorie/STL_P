#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ���� ��ȣ: 2667(������ȣ���̱�)

// BFS�� ����� ť
queue<pair<int, int>> q;
// �湮 ���θ� ����� �迭
bool visited[26][26];
// ������ ����� �迭
string s[25];
// ������ ���� ����
int n;
// ��ǥ �̵��� �迭
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nums = 0;
	vector<int> x;

	// �ʱ�ȭ ����
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
		}
	}

	

	// �湮���� ���� ���� ã�ư���.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == '1')
			{
				if (visited[i][j] == false) // �湮���� ���� ���̶��
				{
					int cnt = 1; // ���� ���� �� ����
					q.push({ i,j }); // ť�� ���� �ִ´�.
					visited[i][j] = true;

					while (q.empty() != true) // BFS�� �����Ѵ�.
					{
						pair<int, int> current = q.front(); q.pop();
						
						for (int t = 0; t < 4; t++)
						{
							int nx = current.first + dx[t];
							int ny = current.second + dy[t];

							// ���� ��Ż �˻�
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (visited[nx][ny] == true || s[nx][ny] == '0') continue;
						
							visited[nx][ny] = true; // �湮�ߴٰ� ǥ���Ѵ�.
							cnt++;
							q.push({ nx, ny });
						}
					}
					x.push_back(cnt);
				}
			}	
		}
	}
	cout << x.size() << '\n';
	sort(x.begin(), x.end());
	for (int i = 0; i < x.size(); i++)
	{
		cout << x[i] << '\n';
	}
}