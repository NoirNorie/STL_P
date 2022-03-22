// 1292: 쉽게 푸는 문제
// 순열 만들기 문제같다

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b; cin >> a >> b;
	int idx = 1;
	vector<int> vc;
	vc.push_back(0);
	bool chk = false;
	while (chk == false)
	{
		for (int i = 0; i < idx; i++)
		{
			vc.push_back(idx);
			if (vc.size()-1 >= b)
			{
				int sum = 0;
				for (int i = a; i <= b; i++)
				{
					sum += vc[i];
				}
				cout << sum << '\n';
				chk = true;
				break;
			}
		}	
		idx++;
	}
}
