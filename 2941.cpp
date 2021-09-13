#include <iostream>
#include <string>
using namespace std;

// 문제 번호: 2941(크로아티아 알파벳)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string x; cin >> x;
	string::iterator ster, seer; // 현재 위치를 나타낼 반복자와 앞을 볼 반복자
	int cnt = 0;

	ster = x.begin();
	while (ster != x.end())
	{
		seer = ster; // 위치 초기화
		if (*ster == 'c')
		{
			seer++;
			if (*seer == '-' || *seer == '=')
			{
				cnt++;
				ster += 2; // 두 칸 이동
			}
			else
			{
				cnt++;
				ster++;
			}
		}
		else if (*ster == 'n' || *ster == 'l')
		{
			seer++; // 다음 알파벳을 확인한다
			if (*seer == 'j')
			{
				cnt++;
				ster += 2; // 두 칸 이동
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
				else // dz= 가 아니면 의미가 없음
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