#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 11504(가장 긴 바이토닉 수열)
// LIS 문제 - DP 풀이법

inline int MAX(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int N; cin >> N;
	vector<int> v(N+1, 0);
	vector<int> up(N+1, 0);
	vector<int> dn(N+1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	for (int i = 1; i <= N; i++)
	{
		up[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (v[j] < v[i]) // 증가하는 부분이라면
			{
				up[i] = MAX(up[i], up[j] + 1); // 더 긴 부분 증가 수열을 구해본다
			}
		}
	}

	for (int i = N; i >= 1; i--)
	{
		dn[i] = 1;
		for (int j = N; j >= i ;j--)
		{
			if (v[i] > v[j]) // 감소하는 부분이라면
			{
				dn[i] = MAX(dn[i], dn[j] + 1);
			}
		}
	}

	int result = 0;
	for (int i = 0; i <= N; i++)
	{
		result = MAX(result, up[i] + dn[i] - 1);
	}
	cout << result<< '\n';


	return 0;
}