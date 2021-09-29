#include <iostream>
#include <cmath>
using namespace std;

// 문제 번호: 1676(팩토리얼 0의 개수)

// 끝자리에 0 이 나올려면 2와 5가 만나거나 10이 나와야 한다.
// 자연수에서 어떠한 경우에도 5보다 2가 많이 등장하므로 2의 개수는 셀 필요 없다.
// 구하려는 숫자까지 5의 개수가 문제의 답

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n; cin >> n;
	int sum = 0;

	while (n >= 5)
	{
		sum += n / 5;
		n /= 5;
	}

	cout << sum << '\n';


	return 0;
}