#include <iostream>
using namespace std;

// 문제 번호: 1934(최소 공배수)

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x, y; cin >> x >> y;

		cout << (x * y) / gcd(x, y) << '\n';
		// 최소 공배수 * 최대 공약수 = x * y
	}

	return 0;
}