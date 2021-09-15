#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 1932(정수 삼각형)

int T[501][501] = { -1 }; // 그냥 기분이 -1을 쓰고 싶었음
int D[501][501] = { -1 }; // 그러하였음

inline int Max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> T[i][j];
		}
	}

	D[0][0] = T[0][0];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == j) // 아래로 그냥 더해서 내려가는 경우 1
			{
				D[i][j] = T[i][j] + D[i-1][j-1];
			}
			else if (j == 0) // 아래로 그냥 더해서 내려가는 경우 2
			{
				D[i][j] = T[i][j] + D[i - 1][j];
			}
			else // 비교가 필요한 경우
			{
				D[i][j] = T[i][j] + Max(D[i - 1][j - 1], D[i - 1][j]);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		result = Max(result, D[N - 1][i]);
	}

	cout << result << '\n';

	return 0;
}