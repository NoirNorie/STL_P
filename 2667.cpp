#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 문제 번호: 2667(단지번호붙이기)

// BFS에 사용할 큐
queue<pair<int, int>> q;
// 방문 여부를 기록할 배열
bool visited[26][26];
// 영역을 기록할 배열
string s[25];
// 영역을 받을 변수
int n;
// 좌표 이동용 배열
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nums = 0;
	vector<int> x;

	// 초기화 동작
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

	

	// 방문하지 않은 곳을 찾아간다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == '1')
			{
				if (visited[i][j] == false) // 방문하지 않은 곳이라면
				{
					int cnt = 1; // 단지 수를 셀 변수
					q.push({ i,j }); // 큐에 집어 넣는다.
					visited[i][j] = true;

					while (q.empty() != true) // BFS를 시작한다.
					{
						pair<int, int> current = q.front(); q.pop();
						
						for (int t = 0; t < 4; t++)
						{
							int nx = current.first + dx[t];
							int ny = current.second + dy[t];

							// 범위 이탈 검사
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (visited[nx][ny] == true || s[nx][ny] == '0') continue;
						
							visited[nx][ny] = true; // 방문했다고 표시한다.
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