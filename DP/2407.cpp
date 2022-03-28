// 2407: 조합
// 동적 계획법의 구성요소 중 하나인 메모이제이션 기법과 관련된 문제
// 추가적으로 long long으로도 표현 불가능한 큰 값이 나오므로 string으로 처리해야 한다.
// string 덧셈 문제도 곁다리로 껴져 있는 문제

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> dp; // 메모이제이션 벡터

string add(string a, string b)
{
    string s = "";
    int len = max(a.length(), b.length());
    int alen = a.length() - 1, blen = b.length() - 1;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (a.length() > i) sum += a[alen - i] - '0';
        if (b.length() > i) sum += b[blen - i] - '0';
        s += sum % 10 + '0';
        sum /= 10;
    }
    if (sum != 0)
    {
        s += sum +'0';
    }
    string result(s.rbegin(), s.rend());
    return result;

}

string comb(int n, int m)
{
    if (n == m || m == 0) // 고정 값 1
    {
        return "1"; // n = m 또는 m = 0이면 무조건 1이다
    }
    else if (m == 1) // 고정 값 2
    {
        return to_string(n); // m = 1이면 무조건 n을 반환함
    }
    else
    {
        if (dp[n][m] != "0") // 이미 기록된 값이 있다면
        {
            return dp[n][m];
        }
        else // 없다면
        {
            dp[n][m] = add(comb(n - 1, m - 1), comb(n - 1, m));
            return dp[n][m];
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    dp.assign(n+1, vector<string>(m+1, "0"));
    cout << comb(n, m) << '\n';

}
