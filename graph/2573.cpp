// 2573: 빙산
// 탐색은 생각보다 쉬움
// 문제를 제대로 안읽어서 빙산을 녹이는 것에서 시간을 잡아먹음

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int>> qe;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    // 빙산
    vector<vector<int>> vct(n, vector<int>(m));

    for (size_t i = 0; i < vct.size(); i++) for (size_t j = 0; j < vct[i].size(); j++) cin >> vct[i][j];
    int year = 0;
    bool chk;
    bool comp = false;
    while (comp == false)
    {
        chk = false;
        int cnt = 0;
        // 방문 배열
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (size_t i = 0; i < vct.size(); i++)
        {
            for (size_t j = 0; j < vct[i].size(); j++)
            {
                if (vct[i][j] > 0 && visited[i][j] == false) // 방문하지 않은 빙산일 때
                {
                    chk = true;
                    qe.push({ i, j });
                    visited[i][j] = true;
                    while (qe.empty() != true)
                    {
                        int cy = qe.front().first;
                        int cx = qe.front().second;
                        qe.pop();
                        for (int i = 0; i < 4; i++)
                        {
                            int ny = cy + dy[i];
                            int nx = cx + dx[i];
                            if (ny < 1 || nx < 1 || ny >= n - 1 || nx >= m - 1) continue;
                            if (visited[ny][nx] == true) continue;
                            if (vct[ny][nx] == 0) continue;

                            visited[ny][nx] = true;
                            qe.push({ ny, nx });
                        }
                    }
                    cnt++;
                    if (cnt >= 2)
                    {
                        cout << year << '\n';
                        comp = true; break;
                    }
                }
            }
            if (comp == true) break;
        }
        if (chk == false)
        {
            cout << 0 << '\n';
            break;
        }
        // 빙산 녹이기
        vector<vector<int>> tmp = vct; // 벡터 복사
        for (size_t i = 0; i < vct.size(); i++)
        {
            for (size_t j = 0; j < vct[i].size(); j++)
            {
                if (vct[i][j] > 0)
                {
                    int melt = 0;
                    if (vct[i - 1][j] == 0) melt++;
                    if (vct[i + 1][j] == 0) melt++;
                    if (vct[i][j - 1] == 0) melt++;
                    if (vct[i][j + 1] == 0) melt++;
                    tmp[i][j] -= melt;
                    if (tmp[i][j] < 0) tmp[i][j] = 0;
                }
            }
        }
        vct = tmp;
        year++;
    }
}
