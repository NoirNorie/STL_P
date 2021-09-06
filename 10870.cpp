#include <iostream>
using namespace std;

// 문제 번호: 10870(피보나치 수열)

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