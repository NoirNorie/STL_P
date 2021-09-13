#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 문제 번호: 1021(회전하는 큐)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	deque<int> dq;
	vector<int> v;
	int t = 0, vi = 0;
	int N, M, Num;
	int srch =0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> Num;
		v.push_back(Num);
	}

	while (vi != v.size())
	{
		for (int i = 0; i < dq.size(); i++)
		{
			if (dq.front() == v[vi]) // 위치를 찾는다.
			{
				srch = i;
			}
			dq.push_back(dq.front());
			dq.pop_front();
		}

		if (srch <= dq.size() / 2)
		{
			while (v[vi] != dq.front())
			{
				dq.push_back(dq.front());
				dq.pop_front();
				t++;
			}
			dq.pop_front();
		}
		else
		{
			while (v[vi] != dq.front())
			{
				dq.push_front(dq.back());
				dq.pop_back();
				t++;
			}
			dq.pop_front();
		}
		vi++;
	}

	cout << t << '\n';

}
