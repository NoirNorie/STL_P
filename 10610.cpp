# 10610: 30

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string T; cin >> T;
    bool chk = false;
    long long sum = 0;
    vector<char>st;
    string x = "";
    for (size_t i = 0; i < T.length(); i++) // 배수 판정법을 이용하면 빠르다.
    {
        if (T[i] == '0') chk = true;
        else sum += T[i]- '0' ;
        st.push_back(T[i]);
    }
    if (chk != true || sum % 3 != 0) // 3의 배수가 아니고 0이 없다면 만들 수 없음
    {
        cout << -1 << '\n';
    }
    else
    {
        sort(st.begin(), st.end(), greater<char>());
        for (auto e : st) x += e;
        cout << x << '\n';
    }
}
