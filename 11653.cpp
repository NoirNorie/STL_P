#include <iostream>
using namespace std;

// ���� ��ȣ: 11653(���μ�����)

int main()
{
	int N;
	cin >> N;

	if (N == 1)
	{
		return 0;
	}
	else
	{
		int d = 2;

		while (N >= d)
		{
			if (N % d == 0) // �������ٸ�
			{
				cout << d << '\n'; // ���� ���� �ѹ� ����Ѵ�
				N = N / d; // ���� N�� ������ ��
			}
			else // �������� �ʴ´ٸ�
			{
				d++; // ���� ���� �Ѿ��
			}
		}
	}

	return 0;
}