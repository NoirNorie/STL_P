#include <iostream>
#include <queue>
using namespace std;

// 문제 번호: 1926(그림)
// BFS 문제

// 영역을 표시할 배열
int board[502][502];
// 방문 여부를 기록할 배열
bool visited[502][502];
// 영역을 제한할 배열
int n, m;
// 상하좌우로 움직이기 편하게 하기 위한 배열
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	queue<pair<int, int>> q;

	cin >> n >> m;

	int max = 0; // 가장 넓은 영역을 기록할 변수
	int cnt = 0; // 그림의 개수를 셀 변수

	// 영역 정보를 입력받는다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	// 그림을 찾아간다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 색칠된 부분인데 방문하지 않은 영역이라면
			if (board[i][j] == 1 && visited[i][j] == false)
			{
				// 여기서 BFS를 실행한다.
				visited[i][j] = true;
				q.push({ i,j });
				
				int size = 1; // 시작한 지점부터 크기를 측정
				cnt++; // 개수 하나를 추가해준다.

				while (q.empty() != true)
				{
					// 현재 좌표 지정
					pair<int, int> cur = q.front(); q.pop();
					for (int t = 0; t < 4; t++)
					{
						// 다음 좌표 지정
						int nx = cur.first + dx[t];
						int ny = cur.second + dy[t];

						// 영역 초과 처리
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						// 방문한 지점이거나 색칠된 부분이 아닌 부분 처리
						if (visited[nx][ny] == true || board[nx][ny] == 0) continue;

						// 조건을 다 통과했으면 이동 가능한 지점이므로
						visited[nx][ny] = true;
						q.push({ nx, ny });
						size++;
					}
				}

				// BFS를 통과한 후 크기를 비교한다.
				if (size > max) max = size;
			}

		}
	}

	// 결과 출력
	cout << cnt << '\n';
	cout << max << '\n';
	

	return 0;
}