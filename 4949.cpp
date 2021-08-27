#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 문제번호: 4949(균형잡힌 세상)

int main()
{
	string str;
	while(1)
	{	
		int chk = 0;
		stack<char> input; // 검사용 스택 생성

		getline(cin, str, '\n');

		if (str == ".") // 탈출 조건
			break;

		for (int i = 0; i < str.length(); i++)
		{
			if (str.at(i) == '.') break; // . 만나면 종료

			if (str.at(i) == '(') // 여는 소괄호라면
			{
				input.push('('); // 스택에 넣는다.
			}
			else if (str.at(i) == '[') // 여는 대괄호라면
			{
				input.push('['); // 이것도 스택에 넣는다.
			}
			else // 남은 경우는 닫는 일반 문자 또는 닫는 소괄호, 대괄호
			{
				if (str.at(i) == ']') // 닫는 대괄호일 경우
				{
					if (input.empty() == 1) // 스택이 비어있으면 조건에 맞지 않다.
					{
						chk = 1; // 플래그 변수에 체크
						break;
					}
					else if (input.top() == '(') // 스택이 비지 않았지만 짝이 맞지 않는다면 조건에 맞지 않음
					{
						chk = 1;
						break;
					}
					else // 나머지 경우는 조건에 맞으므로 대괄호 하나를 pop 함
					{
						input.pop(); 
					}
				}
				else if (str.at(i) == ')') // 닫는 소괄호일 경우
				{
					if (input.empty() == 1) // 스택이 비어있으면 조건에 맞지 않다.
					{
						chk = 1; // 플래그 변수에 체크
						break;
					}
					else if (input.top() == '[') // 스택이 비지 않았지만 짝이 맞지 않는다면 조건에 맞지 않음
					{
						chk = 1;
						break;
					}
					else // 나머지 경우는 조건에 맞으므로 대괄호 하나를 pop 함
					{
						input.pop();
					}
				}

			}
		}

		if (chk == 1 || input.empty() == 0) // 플래그가 변하였거나 스택이 비어있지 않으면 조건에 맞지 않음
		{
			cout << "no" << endl;
		}
		else
		{
			cout << "yes" << endl;
		}

	} 
	// while (str != ".");

	return 0;
}