// 5568: 카드 놓기
// 백트래킹과 셋을 이용하여 풀이함

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

set<string> st;
vector<bool> visited;
vector<int> vct;
int n, k;
void btrk(int l, string s)
{
    if (l == k)
    {
        st.insert(s);
        return;
    }
    for (int i = 0; i < vct.size(); i++)
    {
        if (visited[i] == false) // 방문한 적 없어야 한다.
        {
            visited[i] = true;
            string tmp = s;
            s += to_string(vct[i]);
            btrk(l + 1, s);
            s = tmp;
            visited[i] = false;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    vct.assign(n, 0);
    for (size_t i = 0; i < vct.size(); i++) cin >> vct[i];
    visited.assign(n, false);


    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        string tmp = ""; tmp += to_string(vct[i]);
        btrk(1, tmp);
        visited[i] = false;
    }

    cout << st.size();
}
