#include <iostream>
#include <string>
using namespace std;

// 문제 번호: 5622(다이얼)

int Location(string::iterator ster)
{
	if (*ster >= 65) // ABC
	{
		if (*ster >= 68) // DEF
		{
			if (*ster >= 71) // GHI
			{
				if (*ster >= 74) // JKL
				{
					if (*ster >= 77) // MNO
					{
						if (*ster >= 80) // PQRS
						{
							if (*ster >= 84) // TUV
							{
								if (*ster >= 87) // WXYZ
								{
									return 10;
								}
								else return 9;
							}
							else return 8;
						}
						else return 7;
					}
					else return 6;
				}
				else return 5;
			}
			else return 4;
		}
		else return 3;
	}
	else return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string x; cin >> x;
	
	int sum = 0;

	string::iterator ster = x.begin();
	while (ster != x.end())
	{
		sum += Location(ster++);
	}

	cout << sum << '\n';

	return 0;
}