// 2468: 안전 영역

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> qu;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int max_cnt = 0, cnt = -1;
    vector<vector<int>> area(n, vector<int>(n, 0)), test;
    for (size_t i = 0; i < area.size(); i++) for (size_t j = 0; j < area[i].size(); j++) cin >> area[i][j];

    int level = 0;
    while (cnt != 0) // 높이 제한이 나와있지 않아 반복함
    {
        test = area; // 벡터 복사
        vector<vector<bool>> visit(n, vector<bool>(n, false)); // 방문 벡터

        for (size_t i = 0; i < test.size(); i++)
        {
            for (size_t j = 0; j < test[i].size(); j++)
            {
                if (test[i][j] <= level) test[i][j] = 0; // 해당 영역을 침수시킨다.
                else test[i][j] = -1; // 안전지대 표시
            }
        }

        cnt = 0;
        for (size_t i = 0; i < test.size(); i++)
        {
            for (size_t j = 0; j < test[i].size(); j++)
            {
                if (test[i][j] == -1 && visit[i][j] == false) // 침수되지 않고 방문하지 않은 지역이라면
                {
                    qu.push({ i,j }); // 해당 좌표로 BFS를 수행한다.
                    test[i][j] = true;
                    while (qu.empty() != true)
                    {
                        int cy = qu.front().first, cx = qu.front().second;
                        qu.pop();

                        for (int t = 0; t < 4; t++)
                        {
                            int ny = cy + dy[t], nx = cx + dx[t];
                            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                            if (visit[ny][nx] == true) continue;
                            if (test[ny][nx] == 0) continue;
                            visit[ny][nx] = true; // 방문 표시
                            qu.push({ ny, nx }); // 다음 좌표 추가
                        }
                    }
                    cnt++;
                }
            }
        }
        max_cnt = max(cnt, max_cnt);
        level++;
    }
    cout << max_cnt << '\n';
}
