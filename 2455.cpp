// 2455: 지능형 기차

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int mx = 0, current = 0;
	int n = 4; // 역 수
	for (int i = 0; i < n; i++)
	{
		int in, out;
		cin >> out >> in;
		current += in - out;
		mx = max(mx, current);

	}
	cout << mx << '\n';
}
