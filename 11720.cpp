#include <iostream>
#include <string>
using namespace std;

// 문제 번호: 11720

int main()
{
	int N; cin >> N; // 숫자의 개수 입력
	string x; cin >> x;
	int sum = 0;
	for (int i = 0; i < x.length(); i++)
	{
		sum += (x[i] - 48);
	}

	cout << sum << '\n';

	return 0;
}