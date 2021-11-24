#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mx = -2147483646; int mn = 2147483647;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	

	int n; cin >> n; // 수의 개수 입력
	vector<int> nums(n); // 그만큼 벡터 공간을 만든다

	for (int i = 0; i < n; i++) // 숫자를 입력받는다.
	{
		cin >> nums[i];
	}

	vector<int> vc(n - 1);
	int x = 0;
	for (int i = 0; i < 4; i++)
	{
		int tmp; cin >> tmp;
		for (int j = 0; j < tmp; j++)
		{
			if (i == 0)
				vc[x++] = '+';
			else if (i == 1) 
				vc[x++] = '-';
			else if (i == 2)
				vc[x++] = '*';
			else
				vc[x++] = '/';
		}
	}

	sort(vc.begin(), vc.end());

	do
	{
		int calc = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int y = nums[i];
			char opr = (char)vc[i - 1];
			switch (opr)
			{
			case '+':
				calc += y;
				break;
			case '-':
				calc -= y;
				break;
			case '*':
				calc *= y;
				break;
			case '/':
				calc /= y;
				break;
			}
		}
		mx = max(mx, calc);
		mn = min(mn, calc);
	} while (next_permutation(vc.begin(), vc.end()));

	cout << mx << '\n';
	cout << mn << '\n';	

	return 0;
}
