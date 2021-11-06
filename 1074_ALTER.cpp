#include <iostream>
#include <cmath>
using namespace std;

// ���� ��ȣ: 1074(Z)
// ��� ��츦 �� ������ �ʿ� ���� ã�� �� �ִ�.

int func(int s, int r, int c)
{
	if (s == 0)
	{
		return 0;
	}
	else
	{
		int ns = 1 << (s - 1);

		if (r < ns && c < ns)
		{
			return func(s - 1, r, c);
		}
		if (r < ns && c >= ns)
		{
			return ns * ns + func(s - 1, r, c - ns);
		}
		if (r >= ns && c < ns)
		{
			return 2 * ns * ns + func(s - 1, r - ns, c);
		}
		return 3 * ns * ns + func(s - 1, r - ns, c - ns);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, r, c;
	cin >> n >> r >> c;

	cout << func(n, r, c) << '\n';
	return 0;
}