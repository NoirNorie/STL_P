#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int Div_Sum(int IN);

// ������ȣ: 2231 (������)
int main()
{
	int IN; // �Է¹��� ����
	cin >> IN;

	cout << Div_Sum(IN);

	return 0;
}

int Div_Sum(int IN)
{
	int result = 0;
	int min = IN; // �����ڴ� �Էµ� �������� ���� ���̴�.
	int tmp = 0; // ���� ����

	for (int d = IN; d > 0; d--) // ������ ��� ��츦 �����Ѵ�.
	{
		tmp = d;

		// �ڸ��� ����
		vector<int> Nums; // �ڸ����� ������ ����
		for (int i = 1; i <= 7; i++)
		{
			Nums.push_back(((d % (int)(pow(10, i))) / pow(10, i - 1)));
		}
		// ���Ϳ��� 1, 10, 100, ... �ڸ��� ������ ����ȴ�.

		// �� �ڸ����� �����ڸ� ���Ѵ�.
		vector<int>::iterator iter;
		for (iter = Nums.begin(); iter != Nums.end(); iter++)
		{
			tmp += *iter;
		}

		if (tmp == IN) // ������ ����� �Էµ� �ڿ����� ������ ��� �������̴�.
		{
			if (d < min) // ���� ���� �����ڸ� ã�Ƴ��ٸ�
			{
				min = d; // ã�Ƴ� ������ ���� ���� �����ڷ� ����Ѵ�.
			}
		}
		tmp = 0; // ���� ���� �ʱ�ȭ
	}

	if (min != IN)
	{
		return min;
	}
	else // �����ڰ� ���� ��� ����
	{
		return 0;
	}
}