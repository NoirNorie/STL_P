// 2636: 치즈
// 귀찮은 bfs 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int>> bfsq;
vector<vector<int>> vct, cpy;
vector<vector<bool>> visited;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    vct.assign(n, vector<int>(m));

    for (size_t i = 0; i < vct.size(); i++) for (size_t j = 0; j < vct[i].size(); j++)  cin >> vct[i][j];

    bool chk = true;
    int time = 0;
    int no = 0;
    while (true)
    {
        chk = false;
        int area = 3;
        vector<vector<int>> cpy = vct;
        int nums = 0;
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < m; b++)
            {
                if (cpy[a][b] == 1)
                {
                    nums++;
                }
            }
        }
        if (nums > 0) no = nums;
        visited.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vct[i][j] == 0) // 치즈가 아닌 구역을 표시한다.
                {
                    bfsq.push({ i, j });
                    visited[i][j] = true;
                    while (bfsq.empty() != true)
                    {
                        int y = bfsq.front().first, x = bfsq.front().second;
                        vct[y][x] = area;
                        bfsq.pop();
                        for (int d = 0; d < 4; d++)
                        {
                            int ny = y + dy[d]; int nx = x + dx[d];
                            if (nx < 0 || ny < 0 || ny >= n || nx >= m) continue;
                            if (visited[ny][nx] == true || vct[ny][nx] != 0) continue;
                            bfsq.push({ ny, nx });
                            visited[ny][nx] = true;
                        }
                    }
                    area++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vct[i][j] == 1) // 치즈인 지점에 대해서
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int ny = i + dy[d], nx = j + dx[d];
                        if (nx < 0 || ny < 0 || ny >= n || nx >= m) continue;
                        if (vct[ny][nx] == 3)
                        {
                            cpy[i][j] = 0;
                            break;
                        }
                    }
                    chk = true;
                }
            }
        }
      
        if (chk == true)
        {
            vct = cpy;
            time++;
        }
        else
        {
            cout << time << '\n';
            cout << no << '\n';
            break;
        }
    }

}
