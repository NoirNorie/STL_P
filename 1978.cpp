#include <iostream>
#include <vector>
using namespace std;

// ������ȣ: 1978(�Ҽ� ã��)

int main()
{
	int N, num;
	cin >> N;

	vector<int> v;
	int result = 0;
	int x, chk;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < v.size(); i++)
	{
		x = 2; chk = 0;

		while (v[i] > x)
		{
			if (v[i] == 1 || v[i] % x == 0) // �ڽ� �������� �������� ���� �ִٸ� �Ҽ��� �ƴ�
			{
				chk++;
				break;
			}
			x++;
				
		}
		if (chk == 0 && v[i] != 1) result++;
	}

	cout << result << endl;

	return 0;
}