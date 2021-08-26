#include <iostream>
#include <string>
using namespace std;

//������ȣ: 10828(����)

class Stack
{
	int stack_size; // ������ �ִ� ũ��
	int stack_top; // ������ top�� ����ų ������ �ʱ�ȭ
	int current_size;
	int *stack; // ����

public:

	// �Ҹ��� ������
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
	stack_top = -1; // ������ top�� ����ų ������ �ʱ�ȭ
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
	if (stack_top==-1) return 1; // ������ ��� ����
	else return 0; // ������ ������� ����
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