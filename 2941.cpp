#include <iostream>
#include <string>
using namespace std;

// ���� ��ȣ: 2941(ũ�ξ�Ƽ�� ���ĺ�)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string x; cin >> x;
	string::iterator ster, seer; // ���� ��ġ�� ��Ÿ�� �ݺ��ڿ� ���� �� �ݺ���
	int cnt = 0;

	ster = x.begin();
	while (ster != x.end())
	{
		seer = ster; // ��ġ �ʱ�ȭ
		if (*ster == 'c')
		{
			seer++;
			if (*seer == '-' || *seer == '=')
			{
				cnt++;
				ster += 2; // �� ĭ �̵�
			}
			else
			{
				cnt++;
				ster++;
			}
		}
		else if (*ster == 'n' || *ster == 'l')
		{
			seer++; // ���� ���ĺ��� Ȯ���Ѵ�
			if (*seer == 'j')
			{
				cnt++;
				ster += 2; // �� ĭ �̵�
			}
			else
			{
				cnt++;
				ster++;
			}
		}
		else if (*ster == 's' || *ster == 'z')
		{
			seer++;
			if (*seer == '=')
			{
				cnt++;
				ster += 2;
			}
			else
			{
				cnt++;
				ster++;
			}
		}
		else if (*ster == 'd')
		{
			seer++;
			if (*seer == '-')
			{
				cnt++;
				ster += 2;
			}
			else if (*seer == 'z')
			{
				seer++;
				if (*seer == '=')
				{
					cnt++;
					ster += 3;
				}
				else // dz= �� �ƴϸ� �ǹ̰� ����
				{
					cnt++;
					ster++;
				}
			}
			else
			{
				cnt++;
				ster++;
			}
		}
		else
		{
			cnt++;
			ster++;
		}
	}

	cout << cnt << '\n';
	
	return 0;
}