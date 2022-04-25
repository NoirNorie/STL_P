// 10867: 중복 빼고 정렬하기

#include <iostream>
#include <set>
using namespace std;

set<int> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        st.insert(x);
    }
    for (auto e : st) cout << e << " ";
}
