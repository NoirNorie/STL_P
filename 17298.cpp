#include <iostream>
#include <stack>
#include <vector>
#include <deque>

using namespace std;

// ������ȣ: 17298(��ū��)

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	stack<int> stk;
	vector<int> seq;
	deque<int> deq;
	
	int seq_size; 	// ���� ũ�� �Է�
	int seq_num;	// ���� ����

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