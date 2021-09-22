#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 11399(ATM)

int main()
{
	int N; cin >> N;
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = 0; int wait = 0;
	for (int i = 0; i < N; i++)
	{
		sum += v[i] + wait;
		wait += v[i];
	}

	cout << sum << '\n';
	return 0;
}