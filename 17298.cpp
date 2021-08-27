#include <iostream>
#include <stack>
#include <vector>
#include <deque>

using namespace std;

// 문제번호: 17298(오큰수)

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	stack<int> stk;
	vector<int> seq;
	deque<int> deq;
	
	int seq_size; 	// 수열 크기 입력
	int seq_num;	// 수열 숫자

	cin >> seq_size;

	for (int i = 0; i < seq_size; i++)
	{
		cin >> seq_num;
		seq.push_back(seq_num);
	}

	for (int i = seq_size - 1; i >= 0; i--)
	{
		while ((stk.empty() != 1) && stk.top() <= seq[i])
		{
			stk.pop();
		}

		if (stk.empty() == 1)
		{
			deq.push_front(-1);
		}
		else
		{
			deq.push_front(stk.top());
		}
		stk.push(seq[i]);
	}

	for (int i = 0; i < seq_size; i++)
	{
		cout << deq[i] << " ";
	}


	return 0;
}