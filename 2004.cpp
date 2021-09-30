#include <iostream>
using namespace std;

// ���� ��ȣ: 2004 (���� 0�� ����)
/*
	�ذ��: 2�� 5�� � ���� �ִ��� ã�Ƴ���.
	- ���丮�󿡼��� �������� ��찡 �������� �����Ƿ� 5�� ���ϸ� �Ǿ����� ������ ���� 2�� ���ؾ� �Ѵ�.
	-> 5�� ���� ��� 0�� ��������� �ʴ´�.
	- ���� 2�� 5�� ������ ��� ���ؼ� �� ���� ���� ����ϸ� �ȴ�.
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