#include <iostream>
using namespace std;

// ���� ��ȣ: 10872(���丮��)

int factorial(int n)
{
	if (n == 0) return 1;
	
	return n * factorial(n - 1);
}

int main()
{
	int N; cin >> N;

	cout << factorial(N) << '\n';
	
	return 0;
}