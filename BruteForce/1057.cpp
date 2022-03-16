// 1057: 토너먼트
// 데이터가 부족한건지 예외조건에 대한 처리가 없어도 통과된다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, a, b; cin >> n >> a >> b;
	int r = 0;
	while (a != b)
	{
		if (a % 2 != 0) a = (a + 1) / 2;
		else a /= 2;
		if (b % 2 != 0) b = (b + 1) / 2;
		else b /= 2;
		r++;

	}
	cout << r << '\n';
}
