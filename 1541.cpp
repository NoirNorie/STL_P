#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool neg = false; // ����

// ���� ��ȣ: 1541(�Ҿ���� ��ȣ)
// �����غ��� -�� �ѹ��̶� �����ϸ� �� �����տ� ���ع����� �Ǵ� �� ����.

int Trans(string tmp) // ���ڿ� -> ���� ��ȯ
{
	int num = 0;
	int idx = tmp.length();
	for (int i = idx; i > 0; i--)
	{
		num += (tmp[idx - i] - 48) * pow(10, i-1);
	}
	return num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string x; cin >> x;
	string tmp = "";
	int p_sum = 0;
	int n_sum = 0;

	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == '+')
		{
			if (neg)
			{
				n_sum += Trans(tmp);
			}
			else
			{
				p_sum += Trans(tmp);
			}		
			tmp = "";
		}
		else if (x[i] == '-')
		{
			if (neg)
			{
				n_sum += Trans(tmp);
			}
			else
			{
				p_sum += Trans(tmp);
			}
			neg = true;
			tmp = "";	
		}
		else
		{
			tmp += x[i];
		}
	}

	if (neg) n_sum += Trans(tmp);
	else p_sum += Trans(tmp);

	cout << p_sum - n_sum << '\n';


	return 0;
}