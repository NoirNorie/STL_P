#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ���� ��ȣ: 9020(�������� ����)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, n;
	int flag, chk;


	vector<int> v; // �Ҽ��� ���� ����
	// �˻�
	int max = sqrt(10000); // ������ ���� ���� �Ҽ��� ��� ã�Ƴ� �����Ѵ�.

	for (int i = 2; i <= 10000; i++) // 1�� �Ҽ��� �ƴϴ�.
	{
		flag = 0;
		chk = 2;

		while (chk <= max) // �Ҽ� �˻�
		{
			if (i != chk && i % chk == 0) // �Ҽ��� �ƴ϶��
			{
				flag = 1; // �Ǻ� ������ üũ�Ѵ�.
				break; // �� �̻� �˻��� �ʿ� ����
			}
			chk++;
		}
		if (flag != 1) v.push_back(i); // �Ҽ��� �ƴϸ� ���Ϳ� ����ִ´�.
	}

	cin >> T;
	pair<int, int> result; 
	for (int trial = 0; trial < T; trial++)
	{
		cin >> n; // ¦�� �Է�

		int index = 0;

		while (v[index] < n)
			index++;

		int min = 99999;
		for (int i = index; i >= 0; i--)
		{
			for (int j = index; j >= 0; j--)
			{
				if (v[i] + v[j] == n)
				{
					if (abs(v[i] - v[j]) < min) // ���̰� ���� ������?
					{
						result.first = v[j];
						result.second = v[i];
						min = v[i] - v[j];
					}
				}
			}
		}
		cout << result.first << " " << result.second << '\n';
	}

	return 0;
}