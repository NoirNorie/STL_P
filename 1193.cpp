#include <iostream>
using namespace std;

// ������ȣ: 1193(�м� ã��)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long T;
	cin >> T;

	if (T == 1)
	{
		cout << 1 << "/" << 1 << '\n';
	}
	else
	{
		long long sum = 1; // ����
		long long p = 1; // ������
		int x = 2; // �м��� �հ�

		// �뷫���� ��ġ�� ã�Ƴ���.
		do
		{
			p++; x++;
			sum = sum + p;
		} while (T > sum);

		// ���� ��ġ�� ã�ư���.
		int u = 1, d = p;
		if (x % 2 == 0) //�ö󰡴� ����
		{
			for (int k = sum; k > T; k--)
			{
				d--; u++;
			}
			cout << u << "/" << d << '\n';
		}
		else //�������� ����
		{
			for (int k = sum; k > T; k--)
			{
				d--; u++;
			}
			cout << d << "/" << u << '\n';
		}
	}
	return 0;
}