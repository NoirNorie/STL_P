#include <iostream>
using namespace std;

void func(int a, int b, int n) // 시작 기둥, 도착 기둥, 원판 개수
{
	if (n == 1)
	{
		cout << a << " " << b << '\n';
		return;
	}
	func(a, 6 - a - b, n - 1);
	cout << a << " " << b << '\n';
	func(6 - a - b, b, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k; cin >> k;

	cout << (1 << k) - 1 << '\n';

	func(1, 3, k);

	return 0;
}