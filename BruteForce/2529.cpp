// 2529: 부등호
// 백트래킹과 세트를 이용하여 간단하게 풀이했다
// 조건으로 걸어야 할 것이 좀 많지만 생각보다 쉽다.

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

set<string> st; // 일단 집어넣으면 세트가 알아서 해줄 것임

int k; // 길이
vector<char> vct;     // 부등호를 담을 벡터
vector<bool> visited; // 백트래킹에 사용할 벡터
void btrk(int n, string s)
{
    if (s.length() == k+1)
    {
        st.insert(s);
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (visited[i] == false) // 일단 방문한 적이 없고
        {
            // 부등호 방향에 따라 다음 식을 결정한다
            if (vct[n-1] == '>')
            {
                if (s[s.length() - 1] - '0' > i) // 현재 숫자가 다음에 들어올 숫자보다 커야 한다
                {
                    visited[i] = true; // 방문 기록
                    string tmp = s;    // 현재 상태를 기록
                    s += to_string(i); // 다음 숫자를 추가
                    btrk(n+1, s);      // 다음 단계로 이동
                    s = tmp;           // 현재 상태를 복원
                    visited[i] = false;// 방문 사실도 복원
                }
            }
            else
            {
                if (s[s.length() - 1] - '0' < i) // 현재 숫자가 다음 숫자보다 작아야한다
                {
                    visited[i] = true;
                    string tmp = s;
                    s += to_string(i);
                    btrk(n + 1, s);
                    s = tmp;
                    visited[i] = false;
                }
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    vct.assign(k, ',');
    visited.assign(10, false);
    for (size_t i = 0; i < vct.size(); i++) cin >> vct[i];
    for (int i = 0; i < 10; i++)
    {
        visited[i] = true;
        string str = ""; str += to_string(i);
        btrk(1, str); // 될지 안될지는 모르지만 일단 백트래킹을 시도
        visited[i] = false;
    }
    cout << *st.rbegin() << '\n'; // 세트의 성질로 맨 뒤 갚이 최대 값
    cout << *st.begin() << '\n';  // 맨 앞이 최소 값
}
