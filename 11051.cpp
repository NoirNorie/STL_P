#include <iostream>
using namespace std;

// 문제 번호: 11051(이항 계수 2)
// 이항 계수를 풀 때 팩토리얼로 풀어도 되지만 점화식으로 푸는 것이 더 빠를 수 있다.
// 여기서는 동적 계획법을 사용함

#define _DIV 10007

int memo[1001][1001] = { 0,}; // 메모 배열

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int K; cin >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == j || j == 0)
			{
				memo[i][j] = 1;
			}
			else
			{
				memo[i][j] = (memo[i-1][j] + memo[i-1][j-1]) % _DIV;
			}
		}
	}

	cout << memo[N][K] << '\n';

	return 0;
}