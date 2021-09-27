#include <iostream>
using namespace std;

// ���� ��ȣ: 11051(���� ��� 2)
// ���� ����� Ǯ �� ���丮��� Ǯ� ������ ��ȭ������ Ǫ�� ���� �� ���� �� �ִ�.
// ���⼭�� ���� ��ȹ���� �����

#define _DIV 10007

int memo[1001][1001] = { 0,}; // �޸� �迭

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