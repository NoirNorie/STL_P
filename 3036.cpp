#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 3036(링)
// (가장 큰 톱니바퀴 / 최대 공약수) / (원하는 톱니바퀴 / 최대 공약수)

int gcd(int x, int y)
{
	while (y != 0)
	{
		int n = x % y;
		x = y;
		y = n;
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int front = v[0];

	for (int i = 1; i < v.size(); i++)
	{
		int bot = gcd(front, v[i]);
		cout << front / bot << "/" << v[i] / bot << '\n';
	}

	return 0;
}
