// 1158: 요세푸스 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

deque<int> dq; // 덱을 사용하면 된다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) dq.push_back(i);
	int x = 1;
	cout << "<";
	while (dq.size() != 1)
	{
		if (x == k)
		{
			cout << dq.front() << ", ";
			dq.pop_front();
			x = 1;
		}
		else
		{
			int tmp = dq.front(); 
			dq.pop_front();
			dq.push_back(tmp);
			x++;
		}
	}
	cout << dq.front() << ">";
}
