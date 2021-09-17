#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 2156(포도주 시식)

inline int MAX(int x, int y, int z)
{
	return ((x > y ? x:y) > (y > z ? y:z) ? (x > y ? x : y) : (y > z ? y : z));
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

	DP[0] = 0;
	DP[1] = v[1]; DP[2] = v[1] + v[2];

	for (int i = 3; i <= N; i++)
	{
		DP[i] = MAX(DP[i - 1], DP[i - 2] + v[i], DP[i - 3] + v[i - 1] + v[i]);
	}

	cout << DP[N] << '\n';

	return 0;
}