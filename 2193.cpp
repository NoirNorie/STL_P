#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<vector<long long>> DP(2, vector<long long>(N + 1));

    // 기저 상태 정의
    DP[0][1] = 0; DP[0][2] = 1;
    DP[1][1] = 1; DP[1][2] = 0;

    // DP 동작
    for (int i = 3; i <= N; i++)
    {
        // N 번째 자리에서
        DP[0][i] = DP[0][i - 1] + DP[0][i - 2]; // 끝이 0인 것의 개수
        DP[1][i] = DP[1][i - 1] + DP[1][i - 2]; // 끝이 1인 것의 개수
    }
    // i - 2 번째를 더하는 것은 1로 분기된 경우를 추가하기 위한 것 (1이 연속해서 2번 등장할 수 없으므로 반드시 0인 경우)
    // i - 1 번째에서 0인 경우 만큼 0이 등장할 수 있으므로 더한다.
    // 끝이 1인 경우도 동일함
    // DP[0][i] = DP[0][i-1] + DP[0][i-2];

    cout << DP[0][N] + DP[1][N] << '\n';
    
	return 0;
}
