// 16234: 인구이동
// BFS를 이용하여 그래프 탐색과 관련된 사항도 존재함
// 하지만 BFS는 거드는 것 같은 느낌의 문제임

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

queue<pair<int, int>> qe;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, l, r; cin >> n >> l >> r;

	vector<vector<int>> vc(n, vector<int>(n));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	for (size_t i = 0; i < vc.size(); i++)
	{
		for (size_t j = 0; j < vc[i].size(); j++)
		{
			cin >> vc[i][j];
		}
	}

	vector<pair<int, int>> uni;
	bool chk = true;
	int day = 0;
	while (true)
	{
		chk = false; // 더 이상 변화시킬 게 없는지 검사하는 변수
		for (size_t i = 0; i < vc.size(); i++)
		{
			for (size_t j = 0; j < vc[i].size(); j++)
			{
				if (visited[i][j] == false) // 방문하지 않은 지점에 대해서 BFS를 수행한다.
				{
					qe.push({i,j });
					visited[i][j] = true;
					int sum = 0;
					while (qe.empty() != true)
					{
						int cy = qe.front().first;
						int cx = qe.front().second;
						uni.push_back({ cy, cx }); // 연합으로 추가한다.
						sum += vc[cy][cx]; // 해당 지점의 숫자를 더함
						qe.pop();
						for (int t = 0; t < 4; t++)
						{
							int ny = cy + dy[t];
							int nx = cx + dx[t];

							if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue; // 범위이탈 제어
							if (visited[ny][nx] == true) continue; // 방문한 경우 제외

							int dif = abs(vc[cy][cx] - vc[ny][nx]);
							if (dif < l || dif > r) continue;	// 조건 범위에 들어가지 않는 경우 제외

							chk = true; // 적어도 하나의 연합이 형성된다는 사실을 기록한다.
							visited[ny][nx] = true;
							qe.push({ ny, nx }); // 큐에 등록
						}
					}
					if (uni.size() > 1) // 연합을 구성할 수 있다면
					{
						int res = sum / uni.size(); 
						for (size_t i = 0; i < uni.size(); i++)
						{
							vc[uni[i].first][uni[i].second] = res;
						}
					}
					uni.clear();
				}
			}
		}
		if (chk == true)
		{
			day++;
			visited.assign(n, vector<bool>(n, false)); // 방문 기록을 초기화해준다
			uni.clear();
		}
		else break;
	}
	cout << day << '\n';
}
