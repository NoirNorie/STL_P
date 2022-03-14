// 2720: 세탁소 사장 동혁

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	while (n--)
	{
		int d; cin >> d;
		
		cout << d / 25 << " ";
		d %= 25;
		cout << d / 10 << " ";
		d %= 10;
		cout << d / 5 << " ";
		d %= 5;
		cout << d / 1 << '\n';
	}
}
