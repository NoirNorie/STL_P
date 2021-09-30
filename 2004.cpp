#include <iostream>
using namespace std;

// 문제 번호: 2004 (조합 0의 개수)
/*
	해결법: 2와 5가 몇개 남아 있는지 찾아낸다.
	- 팩토리얼에서는 나눠지는 경우가 존재하지 않으므로 5만 구하면 되었지만 조합의 경우는 2도 구해야 한다.
	-> 5만 남을 경우 0이 만들어지지 않는다.
	- 따라서 2와 5의 개수를 모두 구해서 더 작은 것을 출력하면 된다.
*/
inline int MIN(int x, int y)
{
	return x > y ? y : x;
}

pair<long long int, long long int> chk(long long int x)
{
	int a = 0, b = 0;
	int ax = x, bx = x;
	while (ax >= 2)
	{
		a += ax / 2;
		ax /= 2;
	}
	while (bx >= 5)
	{
		b += bx / 5;
		bx /= 5;
	}

	return make_pair(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	long long int n, m;
	cin >> n >> m;

	pair<long long int, long long int> sum;
	pair<long long int, long int> sub;

	sum = chk(n); sub = chk(m);

	sub.first += chk(n - m).first;
	sub.second += chk(n - m).second;

	sum.first -= sub.first;
	sum.second -= sub.second;

	cout << MIN(sum.first, sum.second) << '\n';

	return 0;
}