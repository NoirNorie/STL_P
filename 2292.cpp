#include <iostream>
using namespace std;

// ������ȣ: 2292(����)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long T;
	cin >> T;
	
	if (T == 1) // ��ȭ���� ����
	{
		cout << 1 << '\n';
	}
	else // ��ȭ���� ����Ѵ�
	{
		long long n = 1;
		long long f = 1;

		while (1)
		{
			if (T <= f) break;
			f = f + (6 * n);
			n++;
		}

		cout << n << '\n';
	}

	return 0;
}