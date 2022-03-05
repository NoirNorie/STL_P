# 1009: 분산처리

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n; cin >> n;
	long long x, y;
	while (n--)
	{
		cin >> x >> y;
		int result = 1;
		for (int i = 1; i <= y; i++)
		{
			result = (result * x) % 10; // 너무 큰 값을 사용할 때는 다 구하지 말고 모듈러 연산을 수행한다.
		}
		if (result == 0) cout << 10 << '\n';
		else cout << result << '\n';
	}
}
