#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool neg = false; // 음수

// 문제 번호: 1541(잃어버린 괄호)
// 생각해보면 -가 한번이라도 등장하면 다 음수합에 더해버리면 되는 것 같다.

int Trans(string tmp) // 문자열 -> 숫자 변환
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