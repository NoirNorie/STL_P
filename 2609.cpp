#include <iostream>
using namespace std;

// 문제 번호 :2609
// 최소공배수 * 최대공약수 = A * B

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b; b = r;
	}
	return a;
}


int main()
{
	int x, y;
	cin >> x >> y;

	int d = gcd(x, y);
	int l = x * y / d;

	cout << d << '\n';
	cout << l << '\n';

	return 0;
}