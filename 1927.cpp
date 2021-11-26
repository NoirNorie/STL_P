#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n; // 연산의 개수 입력

	while (n--)
	{
		int o; cin >> o;

		if (o == 0)
		{
			if (pq.empty() == true)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(o);
		}
	}

	return 0;
}
