#include <iostream>
using namespace std;

// ���� ��ȣ: 10870(�Ǻ���ġ ����)

int fibo(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else
	{
		return fibo(n - 2) + fibo(n - 1);
	}
}

int main()
{
	int n; cin >> n;

	cout << fibo(n) << '\n';

	return 0;
}