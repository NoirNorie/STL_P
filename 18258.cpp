#include <iostream>
using namespace std;

// 문제번호: 18258(큐2)

class Q
{
	long long q_size;
	int current_size;
	int q_front;
	int q_back;
	
	int* q;

public:
	// 생성 소멸자
	Q(int s = 2000000);
	~Q();

	// 판별 함수
	int empty();
	
	// 동작 함수
	void push(int x);
	int pop();
	int size();
	int front();
	int back();
};

// 생성 소멸자
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

// 판별 함수
int Q::empty()
{
	if (current_size == 0)
		return 1;
	else
		return 0;
}

// 동작 함수
void Q::push(int x) // 정수 x를 큐에 넣는다
{
	if (empty() == 1 && q_front == -1 && q_back == -1) // 가장 최초 또는 큐에 아무 숫자가 없는 경우
	{
		q_front = 0;
		q_back = 0;
	}
	q[q_back++] = x; // 해당 위치에 값을 삽입하고 back 포인터를 증가시킨다.
	current_size = q_back - q_front; // 현재 사이즈를 갱신한다.
}
int Q::pop()
{
	int tmp;
	if (empty() == 1)
	{
		tmp = -1; // 큐에 정수가 없으면 -1 반환
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