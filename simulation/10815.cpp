// 10815: 숫자 카드
// 정렬 문제라지만 세트의 성질을 이용해서 풀었다
// 메모리 제한이 너무 넉넉해서 이렇게 풀어도 되겠지만 메모리 제한이 빡빡하면 벡터나 배열을 이용해서 정렬로 풀어야 한다.

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

set<string> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        st.insert(s);
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s; cin >> s;
        if (st.find(s) != st.end()) cout << 1 << " ";
        else cout << 0 << " ";
    }
}
