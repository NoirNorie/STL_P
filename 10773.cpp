#include <iostream>
using namespace std;

//문제번호: 10773(제로)

class Stack
{
	int stack_size;
	int current_size;
	int stack_top;

	int* stack;
public:
	// 생성 소멸자
	Stack(int s = 100000);
	~Stack();

	// 삽입 삭제 함수
	void Push(int num);
	int Pop();
	
	// 상태 파악 함수
	bool Empty();
	bool Full();
	int Top();

	// 문제를 위한 함수
	int Calc();

};

Stack::Stack(int s)
{
	stack_size = s;
	stack = new int[stack_size]; // 스택 생성

	stack_top = -1; //스택의 top 초기화
	current_size = 0; // 현재 스택의 크기 초기화
}

Stack::~Stack()
{
	delete stack;
}

void Stack::Push(int num)
{
	if (Full()) // 스택이 가득 차면 강제 반환
	{
		return;
	}
	else
	{
		current_size++; // 현재 스택의 크기를 하나 키운다.
		stack[++stack_top] = num; // 현재 스택의 위치에 값을 저장
	}
}

int Stack::Pop()
{
	if (Empty()) // 스택이 비었으면 -1을 반환
	{
		return -1;
	}
	else // 아니면
	{
		current_size--; // 현재 스택의 크기를 하나 줄인다
		return stack[stack_top--]; // 현재 스택의 값을 반환하고 인덱스를 움직인다.
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
	cin >> t; // 시행 횟수 입력

	for (int i = 0; i < t; i++)
	{
		cin >> IN; // 값 입력
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