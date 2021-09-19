#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 11722(���� �� �����ϴ� �κ� ����)
// LIS ���� - DP Ǯ�̹�

inline int MAX(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int N; cin >> N;
	vector<int> v(N + 1, 0);
	vector<int> DP(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	DP[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		DP[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (v[j] > v[i])
			{
				DP[i] = MAX(DP[i], DP[j] + 1);
			}
		}

	}
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (max < DP[i]) max = DP[i];
	}
	cout << max << '\n';


	return 0;
}