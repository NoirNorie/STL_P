#include <iostream>
#include <string>
using namespace std;

//문제번호: 10828(스택)

class Stack
{
	int stack_size; // 스택의 최대 크기
	int stack_top; // 스택의 top을 가리킬 변수를 초기화
	int current_size;
	int *stack; // 스택

public:

	// 소멸자 생성자
	Stack(int s = 10000);
	~Stack();

	void push(int num);
	int pop();
	int size();
	int empty();
	int top();
};

Stack::Stack(int s)
{	
	stack_size = s;
	stack = new int[stack_size];
	stack_top = -1; // 스택의 top을 가리킬 변수를 초기화
	current_size = 0;
}

Stack::~Stack()
{
	delete stack;
}

void Stack::push(int num)
{
	if (stack_top < stack_size -1)
	{
		stack[++stack_top] = num;
		current_size++;
	}
}

int Stack::pop()
{
	if (stack_top == -1)
	{
		return -1;
	}
	else
	{
		current_size--;
		return stack[stack_top--];	
	}
}

int Stack::size()
{
	return current_size;
}
int Stack::empty()
{
	if (stack_top==-1) return 1; // 스택이 비어 있음
	else return 0; // 스택이 비어있지 않음
}
int Stack::top()
{
	if (stack_top == -1) return -1;
	else return stack[stack_top];
}


int main()
{
	int c, num;
	string cmd;
	Stack s;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> num;
			s.push(num);
		}
		else if (cmd == "pop")
		{
			cout << s.pop() << endl;
		}
		else if (cmd == "size")
		{
			cout << s.size() << endl;
		}
		else if (cmd == "empty")
		{
			cout << s.empty() << endl;
		}
		else if (cmd == "top")
		{
			cout << s.top() << endl;
		}
	}
}