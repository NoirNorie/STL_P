#include <iostream>
#include <string>
using namespace std;

// ���� ��ȣ: 2908(���)

int main()
{
	string x, y;
	cin >> x >> y;
	bool big = false;

	string::reverse_iterator rx = x.rbegin(), ry = y.rbegin();
	// �� ���ڿ��� �ݺ��ڴ� ���ڿ��� �� �ڸ� ����Ų��.
	while (rx != x.rend())
	{
		if ((*rx - 48) > (*ry - 48))
		{
			big = true;
			break;
		}
		else if ((*rx - 48) < (*ry - 48))
		{
			big = false;
			break;
		}
		else // ���� ���� ���� �����Ƿ� ���� �񱳷� �Ѿ��
		{
			rx++; ry++;
		}
	}

	if (big)
	{
		rx = x.rbegin();
		for (rx; rx != x.rend(); rx++)
		{
			cout << *rx;
		}
	}
	else
	{
		ry = y.rbegin();
		for (ry; ry != y.rend(); ry++)
		{
			cout << *ry;
		}
	}
	return 0;
}