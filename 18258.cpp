#include <iostream>
using namespace std;

// ������ȣ: 18258(ť2)

class Q
{
	long long q_size;
	int current_size;
	int q_front;
	int q_back;
	
	int* q;

public:
	// ���� �Ҹ���
	Q(int s = 2000000);
	~Q();

	// �Ǻ� �Լ�
	int empty();
	
	// ���� �Լ�
	void push(int x);
	int pop();
	int size();
	int front();
	int back();
};

// ���� �Ҹ���
Q::Q(int s)
{
	q_size = s;
	q = new int[q_size];
	q_front = -1;
	q_back = -1;
	current_size = q_back - q_front;
}
Q::~Q()
{
	delete[] q;
}

// �Ǻ� �Լ�
int Q::empty()
{
	if (current_size == 0)
		return 1;
	else
		return 0;
}

// ���� �Լ�
void Q::push(int x) // ���� x�� ť�� �ִ´�
{
	if (empty() == 1 && q_front == -1 && q_back == -1) // ���� ���� �Ǵ� ť�� �ƹ� ���ڰ� ���� ���
	{
		q_front = 0;
		q_back = 0;
	}
	q[q_back++] = x; // �ش� ��ġ�� ���� �����ϰ� back �����͸� ������Ų��.
	current_size = q_back - q_front; // ���� ����� �����Ѵ�.
}
int Q::pop()
{
	int tmp;
	if (empty() == 1)
	{
		tmp = -1; // ť�� ������ ������ -1 ��ȯ
	}
	else
	{
		tmp = q[q_front++];
		current_size = q_back - q_front;
	}
	return tmp;
}
int Q::size()
{
	if (current_size <= 0) return 0;
	else return current_size;
}
int Q::front()
{
	if (empty() == 1) return -1;
	else return q[q_front];
}
int Q::back()
{
	if (empty() == 1) return -1;
	else return q[q_back -1];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Q que;
	int T;
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		string cmd;
		cin >> cmd;
		
		if (cmd == "push")
		{
			int num;
			cin >> num;
			que.push(num);
		}
		else if (cmd == "pop")
		{
			cout << que.pop() << '\n';
		}
		else if (cmd == "size")
		{
			cout << que.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout << que.empty() << '\n';
		}
		else if (cmd == "front")
		{
			cout << que.front() << '\n';
		}
		else if (cmd == "back")
		{
			cout << que.back() << '\n';
		}
	}
	return 0;
}