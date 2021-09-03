#include <iostream>
#include <cmath>
#include <deque>
using namespace std;


// ���� ��ȣ: 4948(����Ʈ�� ����)

int main()
{
	int N;

	do
	{
		cin >> N;
		if (N == 0) break;

		int cnt = 0, flag = 0;
		int up = N * 2;
		int down = N + 1; // �ڱ� �ڽ��� �������� �ʴ´�.
		deque<int> dq;

		int max = sqrt(up); // ��������� Ȯ���� ���� ��
		int num = 2; // 2���� Ȯ���Ѵ�.

		for (int i = down; i <= up; i++)
		{
			if (i == 1) flag = 1; // 1�� �Ҽ��� �ƴ�
			else
			{
				for (num = 2; num <= max; num++)
				{
					if (i != num && i % num == 0)
					{
						flag = 1; break; // �ڱ� �ڽ��� �����ϰ� �������� �Ҽ��� �ƴ�
					}
				}
			}	
			if (flag == 0) cnt++;
			flag = 0;
		}

		cout << cnt << '\n';

	} while (N != 0);

	return 0;
}