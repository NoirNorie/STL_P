#include <iostream>
#include <deque>
using namespace std;

// ¹®Á¦¹øÈ£: 10866(µ¦)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	deque<int> dq;

	int T;
	string cmd;
	int Num;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> cmd;
		if (cmd == "push_back")
		{
			cin >> Num;
			dq.push_back(Num);
		}
		else if (cmd == "push_front")
		{
			cin >> Num;
			dq.push_front(Num);
		}
		else if (cmd == "front")
		{
			if (dq.empty() == 1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
			}	
		}
		else if (cmd == "back")
		{
			if (dq.empty() == 1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
			}
		}
		else if (cmd == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty")
		{
			if (dq.empty() == 1)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == "pop_front")
		{
			if (dq.empty() == 1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (cmd == "pop_back")
		{
			if (dq.empty() == 1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
	}

	return 0;
}