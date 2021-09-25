#include <iostream>
using namespace std;

// ���� ��ȣ: 1934(�ּ� �����)

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
		// �ּ� ����� * �ִ� ����� = x * y
	}

	return 0;
}