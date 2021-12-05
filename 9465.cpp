#include <iostream>
#include <vector>
using namespace std;

inline int MAX(int a, int b) // 내장 함수도 있지만 왠지 인라인 함수가 쓰고 싶었다.
{
    return (a > b ? a : b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        vector<vector<int>> sticker(2, vector<int>(n)); // 메모리를 적게 쓰기 위해 여기서 주어진 값으로 벡터를 만든다

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++) // 벡터를 입력받는다
                cin >> sticker[i][j];
        }

        for (int i = 1; i < n; i++) // 동적 계획법 구간
        {
            // 옆으로 더하면서 구해나간다
            sticker[0][i] = MAX(sticker[0][i-1], sticker[1][i-1] + sticker[0][i]);
            sticker[1][i] = MAX(sticker[1][i-1], sticker[0][i-1] + sticker[1][i]);
        }

        cout << (sticker[0][n-1] > sticker[1][n-1] ? sticker[0][n-1] : sticker[1][n-1]) << '\n';
        // 벡터의 맨 마지막 두 값을 두고 비교하면 큰 값을 구할 수 있다
    }

	return 0;
}
