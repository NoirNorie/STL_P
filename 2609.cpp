#include <iostream>
using namespace std;

// ���� ��ȣ :2609
// �ּҰ���� * �ִ����� = A * B

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