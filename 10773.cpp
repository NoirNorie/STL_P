#include <iostream>
using namespace std;

//������ȣ: 10773(����)

class Stack
{
	int stack_size;
	int current_size;
	int stack_top;

	int* stack;
public:
	// ���� �Ҹ���
	Stack(int s = 100000);
	~Stack();

	// ���� ���� �Լ�
	void Push(int num);
	int Pop();
	
	// ���� �ľ� �Լ�
	bool Empty();
	bool Full();
	int Top();

	// ������ ���� �Լ�
	int Calc();

};

Stack::Stack(int s)
{
	stack_size = s;
	stack = new int[stack_size]; // ���� ����

	stack_top = -1; //������ top �ʱ�ȭ
	current_size = 0; // ���� ������ ũ�� �ʱ�ȭ
}

Stack::~Stack()
{
	delete stack;
}

void Stack::Push(int num)
{
	if (Full()) // ������ ���� ���� ���� ��ȯ
	{
		return;
	}
	else
	{
		current_size++; // ���� ������ ũ�⸦ �ϳ� Ű���.
		stack[++stack_top] = num; // ���� ������ ��ġ�� ���� ����
	}
}

int Stack::Pop()
{
	if (Empty()) // ������ ������� -1�� ��ȯ
	{
		return -1;
	}
	else // �ƴϸ�
	{
		current_size--; // ���� ������ ũ�⸦ �ϳ� ���δ�
		return stack[stack_top--]; // ���� ������ ���� ��ȯ�ϰ� �ε����� �����δ�.
	}
}

bool Stack::Empty()
{
	if (stack_top == -1) return true;
	else return false;
}

bool Stack::Full()
{
	if (stack_top == stack_size - 1) return true;
	else return false;
}

int Stack::Top()
{
	if (stack_top == -1) return stack_top;
	else return stack[stack_top];
}

int Stack::Calc()
{
	int result = 0;

	if (stack_top == -1)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < current_size; i++)
		{
			result += stack[i];
		}

		return result;
	}
}

int main()
{
	Stack s;
	int t, IN;
	cin >> t; // ���� Ƚ�� �Է�

	for (int i = 0; i < t; i++)
	{
		cin >> IN; // �� �Է�
		if (IN == 0)
		{
			s.Pop();
		}
		else
		{
			s.Push(IN);
		}
	}

	cout << s.Calc() << endl;

	return 0;
}