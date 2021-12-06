#include <iostream>
#include <vector>
using namespace std;

inline int MAX(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int> p(N + 1); // 가격 벡터
    vector<int> DP(N + 1); // 동적 계획법 벡터
    for (int i = 1; i <= N; i++) // 가격을 입력받는다.
    {
        cin >> p[i];
    }

    // 기저 상태
    DP[1] = p[1];
    
    for (int i = 2; i <= N; i++)
    {
        int m = p[i];
        for (int j = 1; j < i; j++)
        {
            m = MAX(m, DP[j] + p[i - j]);
        }
        DP[i] = m;
    }

    cout << DP[N] << '\n';
   
	return 0;
}
