#include <iostream>
using namespace std;

// ���� ��ȣ: 2581(�Ҽ�)

int main()
{
	int M, N;
	int sum = 0, min = 0, flag = 0;
	int i;
	cin >> M;
	cin >> N;

	int chk = N;

	while (chk >= M)
	{
		i = 2; flag = 0;
		
		if (chk == 1)
		{
			chk--; continue;
		}
		while (chk > i)
		{		
			if (chk % i == 0) // �������� �Ҽ��� �ƴ�
			{
				flag = 1;
				break;
			}
			i++;
		}
		if (flag == 0) // �Ҽ��� �ƴ϶��
		{
			min = chk; // �ּ� ������ �����Ѵ�
			sum += chk; // �հ踦 ���Ѵ�.
		}
		
		chk--;
	}
	if (min == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << sum << '\n';
		cout << min << '\n';
	}

	return 0;
}