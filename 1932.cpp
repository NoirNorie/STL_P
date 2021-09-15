#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 1932(���� �ﰢ��)

int T[501][501] = { -1 }; // �׳� ����� -1�� ���� �;���
int D[501][501] = { -1 }; // �׷��Ͽ���

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
			if (i == j) // �Ʒ��� �׳� ���ؼ� �������� ��� 1
			{
				D[i][j] = T[i][j] + D[i-1][j-1];
			}
			else if (j == 0) // �Ʒ��� �׳� ���ؼ� �������� ��� 2
			{
				D[i][j] = T[i][j] + D[i - 1][j];
			}
			else // �񱳰� �ʿ��� ���
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